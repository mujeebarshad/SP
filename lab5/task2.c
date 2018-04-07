#include <stdio.h>
#include <unistd.h>

#include <fcntl.h>
#include <errno.h>
extern errno;


int main(){
	uid_t ruid, euid, suid;
	gid_t rgid, egid, sgid;
	getresuid(&ruid, &euid, &suid);
	printf("My Real user-ID is: %ld\n", (long)ruid);
	printf("My Effective user-ID is: %ld\n", (long)euid);
	printf("My Saved Set-user-ID is: %ld\n", (long)suid);
	getresgid(&rgid, &egid, &sgid);
	printf("My Real group-ID is: %ld\n", (long)rgid);
	printf("My Effective group-ID is: %ld\n", (long)egid);
	printf("My Saved Set-group-ID is: %ld\n", (long)sgid);



	return 0;
}
