#include <linux/fs.h>
#define DEBUG_FILE_NAME     "/tmp/debug.tmp"
static struct file* debug_filp = NULL;
static loff_t debug_file_pos = 0;
void debug_file_write(const char __user *buf, size_t count)
{
    mm_segment_t old_fs;
    if (!debug_filp) {
        return;
    }
    old_fs = get_fs();
    set_fs(KERNEL_DS);
    if (count != vfs_write(debug_filp, buf, count, &debug_file_pos)) {
        printk("Failed to write debug file/n");
    }
    set_fs(old_fs);
    return;
}
debug_filp = filp_open(DEBUG_FILE_NAME, O_WRONLY, 0);
if (IS_ERR(debug_filp)) {
    printk("amstream: open debug file failed/n");
    debug_filp = NULL;
}
debug_file_write(buf, count);
if (debug_filp) {
    filp_close(debug_filp, current->files);
    debug_filp = NULL;
    debug_file_pos = 0;
}
