#pragma once
#include "necessary_headers.h"
#include "disk.h"

struct bootloader {
    unsigned char ignore1[11];
    unsigned short int bytes_per_sector;
    uint8_t sector_per_clustor;
    unsigned short int num_of_reserved_sectors;
    uint8_t num_of_FATs;
    unsigned short int max_number_of_root_directory_entries;
    unsigned short int total_sector_count;
    unsigned char ignore2;
    unsigned short int sector_per_FAT;
    unsigned short int sector_per_track;
    unsigned short int num_of_heads;
    unsigned char ignore3[4];
    unsigned int total_sector_count_f12; // 0 for fat12 and fat16
    unsigned short int ignore4;
    char boot_signature;
    unsigned int volume_id;
    unsigned char volume_label[11];
    unsigned char file_sys_type[8];
    unsigned char ignore_rest[452];
};