#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>  // For sleep() 
#include <time.h>    // For timestamp 
#include <sys/statfs.h> // For disk usage 

// Define the refresh interval in seconds 
#define REFRESH_INTERVAL_SEC 1 

/** 
 * Helper function to convert bytes to Gigabytes (GB) 
 */ 
double bytes_to_gb(unsigned long long bytes) { 
    return (double)bytes / (1024 * 1024 * 1024); 
} 

/** 
 * 1. Get Memory Usage from /proc/meminfo 
 */ 
void get_memory_usage() { 
    FILE* fp = fopen("/proc/meminfo", "r"); 
    if (fp == NULL) { 
        perror("Error opening /proc/meminfo"); 
        return; 
    } 

    char line[256];
    long long mem_total = 0, mem_free = 0, mem_available = 0; 

    while (fgets(line, sizeof(line), fp)) { 
        sscanf(line, "MemTotal: %lld kB", &mem_total); 
        sscanf(line, "MemFree: %lld kB", &mem_free); 
        sscanf(line, "MemAvailable: %lld kB", &mem_available); 
    } 
    fclose(fp); 

    long long mem_used = mem_total - (mem_available > 0 ? mem_available : mem_free); 
    double percent_used = (double)mem_used / mem_total * 100.0; 

    printf("Memory Usage: %.2f%%\n", percent_used); 
    printf(" - Total: %.2f GB\n", bytes_to_gb(mem_total * 1024)); 
    printf(" - Used: %.2f GB\n", bytes_to_gb(mem_used * 1024)); 
    printf(" - Free: %.2f GB\n", bytes_to_gb((mem_available > 0 ? mem_available : mem_free) * 1024)); 
} 

/** 
 * 2. Get Disk Usage using statfs() 
 */ 
void get_disk_usage(const char* path) { 
    struct statfs stats; 
    if (statfs(path, &stats) == -1) { 
        perror("Error getting disk stats"); 
        return; 
    } 

    unsigned long long total_space = (unsigned long long)stats.f_blocks * stats.f_bsize; 
    unsigned long long available_space = (unsigned long long)stats.f_bavail * stats.f_bsize; 
    unsigned long long used_space = total_space - available_space; 
    double percent_used = (double)used_space / total_space * 100.0; 

    printf("\nStorage Space (%s): %.2f%%\n", path, percent_used); 
    printf(" - Total: %.2f GB\n", bytes_to_gb(total_space)); 
    printf(" - Used: %.2f GB\n", bytes_to_gb(used_space)); 
    printf(" - Free: %.2f GB\n", bytes_to_gb(available_space)); 
} 

/** 
 * 3. Get CPU Usage from /proc/stat 
 */ 
void get_cpu_usage() { 
    static unsigned long long prev_total = 0, prev_idle = 0; 
    unsigned long long total, idle; 
    unsigned long long user, nice, system, iowait, irq, softirq, steal; 

    FILE* fp = fopen("/proc/stat", "r"); 
    if (fp == NULL) { 
        perror("Error opening /proc/stat"); 
        return; 
    } 

    char line[256]; 
    fgets(line, sizeof(line), fp); 
    fclose(fp); 

    sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu", 
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal); 

    total = user + nice + system + idle + iowait + irq + softirq + steal; 
    unsigned long long delta_total = total - prev_total; 
    unsigned long long delta_idle = idle - prev_idle; 

    double cpu_percent = 0.0; 
    if (delta_total > 0) { 
        cpu_percent = (1.0 - (double)delta_idle / delta_total) * 100.0; 
    } 

    printf("CPU Usage: %.2f%%\n", cpu_percent);

    prev_total = total; 
    prev_idle = idle; 
} 

/** 
 * 4. Get Network Speed from /proc/net/dev 
 */ 
void get_network_speed() { 
    static unsigned long long prev_recv = 0, prev_sent = 0; 
    unsigned long long total_recv = 0, total_sent = 0; 

    FILE* fp = fopen("/proc/net/dev", "r"); 
    if (fp == NULL) { 
        perror("Error opening /proc/net/dev"); 
        return; 
    } 

    char line[512]; 
    fgets(line, sizeof(line), fp); 
    fgets(line, sizeof(line), fp); 

    while (fgets(line, sizeof(line), fp)) { 
        char if_name[32]; 
        unsigned long long r_bytes, t_bytes; 
        sscanf(line, "%[^:]: %llu %*u %*u %*u %*u %*u %*u %*u %llu", 
               if_name, &r_bytes, &t_bytes); 

        if (strstr(if_name, "lo") == NULL) { 
            total_recv += r_bytes; 
            total_sent += t_bytes; 
        } 
    } 
    fclose(fp);

    double download_speed_kbs = 0.0; 
    double upload_speed_kbs = 0.0; 

    if (prev_recv > 0 && prev_sent > 0) { 
        download_speed_kbs = (double)(total_recv - prev_recv) / (1024 * REFRESH_INTERVAL_SEC); 
        upload_speed_kbs = (double)(total_sent - prev_sent) / (1024 * REFRESH_INTERVAL_SEC); 
    } 

    printf("\nNetwork Activity (Total):\n"); 
    printf(" - Download Speed: %.2f KB/s\n", download_speed_kbs); 
    printf(" - Upload Speed: %.2f KB/s\n", upload_speed_kbs); 

    prev_recv = total_recv; 
    prev_sent = total_sent; 
} 

/** 
 * Main function 
 */ 
int main() { 
    get_cpu_usage(); 
    get_network_speed(); 

    sleep(REFRESH_INTERVAL_SEC); 

    while (1) { 
        system("clear"); 

        time_t now = time(NULL); 
        printf("--- Linux System Performance Monitor (C) ---\n"); 
        printf("Timestamp: %s", ctime(&now)); 

        get_cpu_usage(); 
        get_memory_usage(); 
        get_disk_usage("/"); 
        get_network_speed(); 

        printf("\nPress Ctrl+C to exit...\n"); 
        sleep(REFRESH_INTERVAL_SEC); 
    } 

    return 0; 
}
