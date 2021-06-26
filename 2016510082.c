#include <linux/module.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
SYSCALL_DEFINE2(2016510082_syscall, int, arg1, int, arg2)
{
	struct file *f;
	char buf[150];
	mm_segment_t fs;
	int i;
	int c = 0;
	for(i=0;i<122;i++)
	    buf[i] = 0;
	 f = filp_open("/proc/cpuinfo", O_RDONLY, 0);
	if(f == NULL)
		printk(KERN_ALERT "filp_open error!!.\n");
	else{
		fs = get_fs();
		set_fs(get_ds());
		f->f_op->read(f, buf, 122, &f->f_pos);
		set_fs(fs);
		printk(KERN_INFO "CPU Information:\n");
		printk(KERN_INFO "%s\n",buf);
        }
	filp_close(f,NULL);
	if(arg1 == 1 || arg1 == 3)
	{
		char buf1[30];
		char buff2[30];
		char buff3[30];
		for(i=0;i<30;i++){
		    buf1[i] = 0;
		}
		f = filp_open("/proc/uptime", O_RDONLY, 0);
		if(f == NULL)
			printk(KERN_ALERT "filp_open error!\n");
		else
		{
			fs = get_fs();
			set_fs(get_ds());
			f->f_op->read(f,buf1,30,&f->f_pos);
			set_fs(fs);
			printk("Parameter#all-System Statistics:\n");
			while (buf1[c] != ' ')
			{ 
                                buff3[c] = buf1[c];
                                c++;
                        }
			printk("system was booted since: %c%c%c%c%c%c", buf1[0], buf1[1], buf1[2], buf1[3], buf1[4], buf1[5]);
			c = c + 1;
			printk("system has been idle since: %c%c%c%c%c%c", buf1[c], buf1[c+1], buf1[c+2], buf1[c+3], buf1[c+4], buf1[c+5]);
		}
		filp_close(f,NULL);
                for(i=0;i<30;i++)
                    buff2[i] = 0;
                f = filp_open("/proc/loadavg", O_RDONLY, 0);
                if(f == NULL)
                        printk(KERN_ALERT "filp_open error!\n");
                else{
                        fs = get_fs();
                        set_fs(get_ds());
                        f->f_op->read(f,buff2,20,&f->f_pos);
                        set_fs(fs);
			printk(KERN_INFO "the number of active tasks: %c", buff2[15]);
			printk(KERN_INFO "the number of processes: %c%c%c", buff2[17], buff2[18], buff2[19]);
			}
		filp_close(f,NULL);
	}
	if(arg1 == 2 || arg1 == 3) 
	{
		char df2[101];
                for(i=0;i<40;i++){
                    df2[i] = 0;
                }
		f = filp_open("/proc/2/status", O_RDONLY, 0);
                if(f == NULL)
                        printk(KERN_ALERT "filp_open error!\n");
                else 
                {
                        fs = get_fs();
                        set_fs(get_ds());
                        f->f_op->read(f,df2,100,&f->f_pos);
                        set_fs(fs);
			printk(KERN_INFO "Parameter#[process_id]-Process Information:");
			printk(KERN_INFO "%s\n",df2);
		}
		filp_close(f,NULL);


	}
    return 0;
}
