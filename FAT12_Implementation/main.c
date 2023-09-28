#include "fat12struct.h"

int main(void) {
    FILE *fp;
    struct bootloader bt;

    fp = fopen("sample_fat.bin", "rb");
    if(fp != NULL) {
        fread(&bt, 512, 1, fp);

        fprintf(stdout, "Ignore: %s (%ld)\n", bt.ignore1, sizeof(bt.ignore1));
        fprintf(stdout, "Bytes per sector: %d (%ld)\n", bt.bytes_per_sector, 
        sizeof(bt.bytes_per_sector));
        fprintf(stdout, "Sector per cluster: %d (%ld)\n", bt.sector_per_clustor, 
        sizeof(bt.sector_per_clustor));
        fprintf(stdout, "Number of reserved sectors: %d (%ld)\n", bt.num_of_reserved_sectors, 
        sizeof(bt.num_of_reserved_sectors));
        fprintf(stdout, "Num_of_FATs: %d (%ld)\n", bt.num_of_FATs, 
        sizeof(bt.num_of_FATs));
        fprintf(stdout, "Max number of root directory entires: %d (%ld)\n", 
        bt.max_number_of_root_directory_entries, sizeof(bt.max_number_of_root_directory_entries));
        fprintf(stdout, "Total sector count: %d (%ld)\n", bt.total_sector_count, 
        sizeof(bt.total_sector_count));
        fprintf(stdout, "Ignore 2: %c (%ld)\n", bt.ignore2, sizeof(bt.ignore2));
        fprintf(stdout, "Sector per FAT: %d (%ld)\n", bt.sector_per_FAT, 
        sizeof(bt.sector_per_FAT));
        fprintf(stdout, "Sector per track: %d (%ld)\n", bt.sector_per_track, 
        sizeof(bt.sector_per_track));
        fprintf(stdout, "Number of heads: %d (%ld)\n", bt.num_of_heads, 
        sizeof(bt.num_of_heads));
        fprintf(stdout, "Ignore 3: %s (%ld)\n", bt.ignore3, sizeof(bt.ignore3));
        fprintf(stdout, "Total_sector_count_F12: %d (%ld)\n", bt.total_sector_count_f12, 
        sizeof(bt.total_sector_count_f12));
        fprintf(stdout, "Ignore 4: %d (%ld)\n", bt.ignore4, sizeof(bt.ignore4));
        fprintf(stdout, "Boot Signature: %c (%ld)\n", bt.boot_signature, 
        sizeof(bt.boot_signature));
        fprintf(stdout, "Volume ID: %d (%ld)\n", bt.volume_id, 
        sizeof(bt.volume_id));
        fprintf(stdout, "Volume Label: %s (%ld)", bt.volume_label, 
        sizeof(bt.volume_label));
        fprintf(stdout, "\n");
        fprintf(stdout, "File System Type: %s (%ld)\n", bt.file_sys_type, sizeof(bt.file_sys_type));
        fprintf(stdout, "Ignore rest: %s (%ld)", bt.ignore_rest, sizeof(bt.ignore_rest));
        // mandatory newline for neat output
        fprintf(stdout, "\n");
    } else {
        fprintf(stderr, "Abnormal Exit");
        return 1;
    }

    return 0;
}