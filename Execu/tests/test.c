#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct s_obj
{
	char	*fname;
	char	*lname;
}				t_obj;

void	free_obj(t_obj obj)
{
	free(obj.fname);
	free(obj.lname);
}
int count_name(char *fname, char *lname)
{
	t_obj obj;

	obj.fname = strdup(fname);
	obj.lname = strdup(lname);

	int len = strlen(obj.fname) + strlen(obj.lname);
	free_obj(obj);
	return (len);
}


int main(void)
{

	int l = count_name("oussama", "bouizgarne");
	printf("my pid is %d", getpid());
	printf("L :  ---%d\n", l);

	while (1); 
	return (0);
}