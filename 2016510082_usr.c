#include <linux/kernel.h>
#include <linux/module.h>
#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char *ch1 = "-all";  //for find systen statistics
    char *ch2 = "-p";    //for find process info
    
    long int result;
    
    //./systeminfo.out  there is no user input, it press cpu informaition oly
	//syscall take two int value if user want to entered -all or -p vs. from out
	//cpu information must be written every condition
	//-all string entered this code enter 1 value for syscall
	//-p string entered this code enter 2 value for syscall
	// -all and -p value entered at the same time 3 enterd for syscall
	//second argument for process id, my code wirte just p_id = 2
	
	//./systeminfo.out -p 1425 > CPU+process detail
	
    if (argc = 3 && strcmp(argv[1], ch2) == 0)
    {
    	result = syscall(548, 2);
	}
	
	
	//./systeminfo.out -all > CPU+system statistics
	else if (argc = 2 && strcmp(argv[1], ch1) == 0)
    {
    	result = syscall(548, 1);
	}
	
	
	//./systeminfo.out -all -p 1425 > CPU+sys.statistics+ps.detail
	else if (argc = 4 && strcmp(argv[2], ch2) == 0 && strcmp(argv[1], ch1) == 0)
	{
		result = syscall(548, 3, 2)
	}
	else
    {
        result = syscall(548);
    }

	
	printf("system call 2016510082 returned %Ld\n", result);
	

	



}
