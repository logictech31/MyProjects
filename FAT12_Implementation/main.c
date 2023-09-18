#include "fat12struct.h"

int main(void) {
    FILE *fp;
    struct bootloader bt;

    fp = fopen("fat_sample.bin", "rb");
    if(fp != NULL) {
        fread(&bt, 512, 1, fp);
        fprintf(stdout, "Boot signature: %c\n", bt.boot_signature);
        fprintf(stdout, "Bytes per sector: %d\n", bt.bytes_per_sector);
        fprintf(stdout, "Sector per cluster: %d\n", bt.sector_per_clustor);
        fprintf(stdout, "Number of reserved sectors: %d\n", bt.num_of_reserved_sectors);
        fprintf(stdout, "Num_of_FATs: %d\n", bt.num_of_FATs);
        fprintf(stdout, "Max number of root directory entires: %d\n", bt.max_number_of_root_directory_entries);
        fprintf(stdout, "Total sector count: %d\n", bt.total_sector_count);
        fprintf(stdout, "Sector per FAT: %d\n", bt.sector_per_FAT);
        fprintf(stdout, "Sector per track: %d\n", bt.sector_per_track);
        fprintf(stdout, "Number of heads: %d\n", bt.num_of_heads);
        fprintf(stdout, "Total_sector_count_F12: %d\n", bt.total_sector_count_f12);
        fprintf(stdout, "Boot Signature: %c\n", bt.boot_signature);
        fprintf(stdout, "Volume ID: %d\n", bt.volume_id);
        fprintf(stdout, "Volume Label: %s", bt.volume_label);
        fprintf(stdout, "\n");
        fprintf(stdout, "File System Type: %s", bt.file_sys_type);
        // mandatory newline for neat output
        fprintf(stdout, "\n");
    } else {
        fprintf(stderr, "Abnormal Exit");
        return 1;
    }

    return 0;
}