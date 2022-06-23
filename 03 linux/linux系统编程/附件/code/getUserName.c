#include <stdio.h>
#include <pwd.h>
#include <grp.h>

/*
char *pw_name;	 // Username.
char *pw_passwd; // Hashed passphrase, if shadow database
				 //			not in use (see shadow.h).
__uid_t pw_uid;	 // User ID.
__gid_t pw_gid;	 // Group ID.
char *pw_gecos;	 // Real name.
char *pw_dir;	 // Home directory.
char *pw_shell;	 // Shell program.
*/
void testUser()
{
	struct passwd *pass = NULL;
	pass = getpwnam("uos");
	if (pass)
	{
		printf("pw_name : %s\n", pass->pw_name);
		printf("pw_passwd : %s\n", pass->pw_passwd);
		printf("pw_uid : %d\n", pass->pw_uid);
		printf("pw_gid : %d\n", pass->pw_gid);
		printf("pw_gecos : %s\n", pass->pw_gecos);
		printf("pw_dir : %s\n", pass->pw_dir);
		printf("pw_shell : %s\n", pass->pw_shell);
	}

	struct passwd *pass2 = NULL;
	pass2 = getpwuid(1001);
	if (pass2)
	{
		printf("pw_name : %s\n", pass2->pw_name);
		printf("pw_passwd : %s\n", pass2->pw_passwd);
		printf("pw_uid : %d\n", pass2->pw_uid);
		printf("pw_gid : %d\n", pass2->pw_gid);
		printf("pw_gecos : %s\n", pass2->pw_gecos);
		printf("pw_dir : %s\n", pass2->pw_dir);
		printf("pw_shell : %s\n", pass2->pw_shell);
	}
}

/* The group structure.	 */
/*
	char *gr_name;		// Group name.
	char *gr_passwd;	// Password.
	__gid_t gr_gid;		// Group ID.
	char **gr_mem;		// Member list.
*/

void testGroup()
{
	struct group *g = getgrnam("sudo");
	if (g)
	{
		printf("gr_name : %s\n", g->gr_name);
		printf("gr_passwd : %s\n", g->gr_passwd);
		printf("gr_gid : %d\n", g->gr_gid);
		int i = 0;
		while (g->gr_mem[i])
		{
			printf("gr_mem : %s\n", g->gr_mem[i]);
			++i;
		}
	}

	struct group *g2 = getgrgid(27);
	if (g2)
	{
		printf("gr_name : %s\n", g2->gr_name);
		printf("gr_passwd : %s\n", g2->gr_passwd);
		printf("gr_gid : %d\n", g2->gr_gid);
		int i = 0;
		while (g2->gr_mem[i])
		{
			printf("gr_mem : %s\n", g2->gr_mem[i]);
			++i;
		}
	}
}

int main()
{
	testGroup();

	return 0;
}
