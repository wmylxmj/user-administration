#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct{
	char name[20];
	char sex[4];
	char age[3];
	char id[18];
	char number[11];
	char job[40];
	char address[40];
}user;

enum task{
	main_menu,
	input_new_users,
	show_users_messages,
	search_users,
	delete_users
};

int line[20]={
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0
};

user users[20];

int now_task = main_menu;

void show_main_menu(void)
{
	printf("\t\t\t\t\t☆☆☆☆☆☆☆移动用户管理系统☆☆☆☆☆☆☆\n\n");
	printf("\t\t\t\t\t              1.新增移动用户数据记录\n\n");
	printf("\t\t\t\t\t              2.用户信息浏览\n\n");
	printf("\t\t\t\t\t              3.修改用户信息\n\n");
	printf("\t\t\t\t\t              4.删除用户信息\n\n");	
	printf("\t\t\t\t\t              5.用户查询\n\n");
	printf("\t\t\t\t\t              6.退出系统\n\n");
	printf("\t\t\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
	printf("请输入你的选择：");
}

void search_menu()
{
	printf("\t\t\t\t\t☆☆☆☆☆☆☆信息查询☆☆☆☆☆☆☆\n\n");
	printf("\t\t\t\t\t            1.按身份证号查询\n\n");
	printf("\t\t\t\t\t            2.按手机号查询\n\n");
	printf("\t\t\t\t\t            3.退出\n\n");
	printf("\t\t\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
	printf("请输入你的选择：");
}

void task_input_new_users(void)
{
	char job[40];
	char id[18];
	char name[20];
	char sex[4];
	char age[3];
	char address[40];
	char number[11];
	char sex1[4]={"男"};
	char sex2[4]={"女"};
	char ch;
	printf("\t\t\t\t你选择的是：新增移动用户数据记录\n\n");
	do{
		FILE *fp_open;//定义指向user.txt文件的指针变量fp
		fp_open = fopen("user.txt", "r+");
		while(!fp_open)
		{
			printf("you created a new file!\n");
			fp_open = fopen("user.txt","w+");
		}
		fclose(fp_open);
		FILE*fp;
		fp = fopen("user.txt", "a+");
		printf ("请输入需要添加用户的信息\n");
		printf("用户名:");
		scanf("%s", name);	
		fprintf(fp, "%-20s\t", name);
		do
		{
			printf("性别：");
			scanf("%s", sex);
			if(strcmp(sex1,sex)==0||strcmp(sex2,sex)==0)
			{
				fprintf(fp, "%-4s\t", sex);
				break;
			}
			else
			{
				printf("请输入男或女！\n");
			}
		}while(1);
		printf("年龄:");
		scanf("%s",age);  
		fprintf(fp, "%-3s\t", age);
		printf("身份证号:");
		scanf("%s", id);
		fprintf(fp, "%-18s\t", id);
		printf("手机号:");
		scanf("%s", number);
		fprintf(fp, "%-11s\t", number);
		printf("职业:");
		scanf("%s", job);
		fprintf(fp, "%-40s\t", job);
		printf("家庭住址:");
		scanf("%s", address);
		fprintf(fp, "%-40s\t", address);
		fprintf(fp,"\n");
		fclose(fp);
		printf ("是否继续？(Y/N)");
		fflush (stdin);
		scanf ("%c" , &ch);
		system("cls");
	}while (ch == 'y'||ch == 'Y');
	now_task = main_menu;
}

void task_show_users_messages(void)
{
	char g;
	char ch;
	printf ("您选择的是用户信息浏览\n");
	printf ("当前用户信息\n");
	FILE*fp;//定义指向文件的指针变量
	fp=fopen("user.txt","r");//打开文件并验证
	if(!fp)
	{
		printf("cannot open file\n");
		exit(0);//退出
	}
	printf("%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", "用户名","性别","年龄","身份证号","手机号","职业","家庭住址");
	while(!feof(fp))
   	{
		ch = fgetc(fp);
		printf("%c", ch);
	}
	fclose(fp);//关闭文件
	fflush(stdin);
	scanf("%c",&g);
	now_task = main_menu;
}

void task_main_menu(void)
{
	int g;
	system ("color b1");
	system("cls");
	show_main_menu();//调用主功能菜单函数		
	scanf("%d",&g);//主菜单变量
	switch(g)
	{
	case 1:
		now_task = input_new_users;
		break;

	case 2:
		now_task = show_users_messages;
		break;

	case 4:
		now_task = delete_users;
		break;

	case 5:
		now_task = search_users;
		break;

	}
}

void line_init(void)
{
	int i = 0;
	for(i=0; i<=19; i++)
	{
		line[i] = 0;
	}
}

void search_id(bool show_flag)
{
	char job[40];
	char id[18];
	char name[20];
	char sex[4];
	char age[3];
	char address[40];
	char number[11];
	char m[20];
	bool flag= false;
	int i=0, j;
	int index = 0;
	line_init();
	FILE*fp;
	if((fp=fopen("user.txt","r+"))==NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
	printf ("请输入想要查询的用户身份证号码：");
	scanf ("%s" , m);
	printf("\n");
	while(!feof(fp))
	{
		//init
		strcpy(name, "0");
		strcpy(sex, "0");
		strcpy(age, "0");
		strcpy(id, "0");
		strcpy(number, "0");
		strcpy(job, "0");
		strcpy(address, "0");
		fscanf(fp,"%s",name);
		fscanf(fp,"%s",sex);
		fscanf(fp,"%s",age);
		fscanf(fp,"%s",id);
		fscanf(fp,"%s",number);
		fscanf(fp,"%s",job);
		fscanf(fp,"%s",address);
		i ++ ;
		if (!strcmp(m,id))//判断想查询的身份证号和已经录入的身份证号是否一致
		{
			line[index] = i;
			index ++ ;
			if(flag == false && show_flag)
			{
				printf("%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", "用户名","性别","年龄","身份证号","手机号","职业","家庭住址");
			}
			flag = true;
			if(show_flag)
			{
				printf("%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", name,sex,age,id,number,job,address);
				printf("\n");
			}
		}
	}
	if(!flag)
	{
		printf("身份证号不存在！\n");
	}
	fclose(fp);	
	for(j=0;j<=19;j++)
	{
		if(line[j] != 0)
		{
			printf("%d", line[j]);
		}
	}
	printf("\n");
}

void search_number(bool show_flag)
{
	char job[40];
	char id[18];
	char name[20];
	char sex[4];
	char age[3];
	char address[40];
	char number[11];
	char m[20];
	bool flag= false;
	int i = 0, j;
	int index = 0;
	line_init();
	FILE*fp;
	if((fp=fopen("user.txt","r+"))==NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
	printf ("请输入想要查询的用户手机号码：");
	scanf ("%s" , m);
	printf("\n");
	while(!feof(fp))
	{
		//init
		strcpy(name, "0");
		strcpy(sex, "0");
		strcpy(age, "0");
		strcpy(id, "0");
		strcpy(number, "0");
		strcpy(job, "0");
		strcpy(address, "0");
		fscanf(fp,"%s",name);
		fscanf(fp,"%s",sex);
		fscanf(fp,"%s",age);
		fscanf(fp,"%s",id);
		fscanf(fp,"%s",number);
		fscanf(fp,"%s",job);
		fscanf(fp,"%s",address);
		i ++ ;
		if (!strcmp(m,number))//判断想查询的身份证号和已经录入的身份证号是否一致
		{
			line[index] = i;
			index ++ ;
			if(flag == false&&show_flag)
			{
				printf("%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", "用户名","性别","年龄","身份证号","手机号","职业","家庭住址");
			}
			flag = true;
			if(show_flag)
			{
				printf("%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", name,sex,age,id,number,job,address);
				printf("\n");
			}
		}
	}
	if(!flag)
	{
		printf("用户手机号码不存在！\n");
	}
	fclose(fp);	
	for(j=0;j<=19;j++)
	{
		if(line[j] != 0)
		{
			printf("%d", line[j]);
		}
	}
	printf("\n");
}

void task_search_users(void)
{
	int q;
	char g;
	system ("cls");
	search_menu();
	scanf ("%d" , &q);
	switch(q)
	{
	case 1:
		search_id(true);
		fflush(stdin);
		scanf ("%c" , &g);
		break;
	case 2:
		search_number(true);
		fflush(stdin);
		scanf ("%c" , &g);
		break;
	case 3:
		now_task = main_menu;
		break;
	}
}

void delete_lines(int *line)
{
	char job[40];
	char id[18];
	char name[20];
	char sex[4];
	char age[3];
	char address[40];
	char number[11];
	int i = 0;
	int j = 0;
	bool write_flag = true;
	FILE*fp_w;
	fp_w=fopen("user_new.txt","w");
	FILE*fp_r;
	fp_r=fopen("user.txt","r");
	while(!feof(fp_r))
	{
		//init
		write_flag = true;
		strcpy(name, "0");
		strcpy(sex, "0");
		strcpy(age, "0");
		strcpy(id, "0");
		strcpy(number, "0");
		strcpy(job, "0");
		strcpy(address, "0");
		fscanf(fp_r,"%s",name);
		fscanf(fp_r,"%s",sex);
		fscanf(fp_r,"%s",age);
		fscanf(fp_r,"%s",id);
		fscanf(fp_r,"%s",number);
		fscanf(fp_r,"%s",job);
		fscanf(fp_r,"%s",address);
		i++;
		for(j = 0; j<=19; j++)
		{
			if(i== *(line+j))
			{
				write_flag = false;
			}
		}
		if(write_flag==true&&strcmp(sex, "0")!=0)
		{
			fprintf(fp_w, "%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", name,sex,age,id,number,job,address);
		}
	}
	fclose(fp_r);
	fclose(fp_w);
	if(remove("user.txt"))
	{
		printf("Could not delete the file.\n");
	}
	else
	{
		printf("OK\n");
	}
	rename("user_new.txt", "user.txt");
}

void show_line(int *line)
{
	bool flag = true;
	char job[40];
	char id[18];
	char name[20];
	char sex[4];
	char age[3];
	char address[40];
	char number[11];
	int i = 0;
	int j = 0;
	bool show_flag = false;
	FILE*fp;
	fp=fopen("user.txt","r");
	while(!feof(fp))
	{
		//init
		show_flag = false;
		strcpy(name, "0");
		strcpy(sex, "0");
		strcpy(age, "0");
		strcpy(id, "0");
		strcpy(number, "0");
		strcpy(job, "0");
		strcpy(address, "0");
		fscanf(fp,"%s",name);
		fscanf(fp,"%s",sex);
		fscanf(fp,"%s",age);
		fscanf(fp,"%s",id);
		fscanf(fp,"%s",number);
		fscanf(fp,"%s",job);
		fscanf(fp,"%s",address);
		i++;
		for(j = 0; j<=19; j++)
		{
			if(i== *(line+j))
			{
				show_flag = true;
			}
		}
		if(show_flag==true&&strcmp(sex, "0")!=0)
		{
			if(flag)
			{
				printf("%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", "用户名","性别","年龄","身份证号","手机号","职业","家庭住址");
				flag = false;
			}
			printf("%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", name,sex,age,id,number,job,address);
		}
	}
	fclose(fp);
}

void task_delete_users(void)
{
	int result = 0;
	int copy_step = 0;
	int a=0, b=0;
	int option;
	char quit_flag;
	char delete_flag;
	char search_further_flag;
	int line2[20]={
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	};
	system ("cls");
	search_menu();
	scanf ("%d" , &option);
	switch(option)
	{
	case 1:
		search_id(true);
		if(line[1]==0 && line[0]!=0)
		{
			fflush(stdin);
			printf("Delete?(Y/N)\n");
			scanf("%c", &delete_flag);
			if(delete_flag=='y'||delete_flag=='Y')
			{
				delete_lines(line);
				fflush(stdin);
				scanf ("%c" , &quit_flag);
			}
		}
		else if(line[1]!=0 && line[0]!=0)
		{
			printf("search further?(Y/N)\n");
			fflush(stdin);
			scanf ("%c" , &search_further_flag);
			if(search_further_flag=='y'||search_further_flag=='Y')
			{
				for(copy_step=0;copy_step<=19;copy_step++)
				{
					line2[copy_step] = line[copy_step];
				}
				search_number(false);
				for(a=0 ; a<=19; a++)
				{
					for(b=0; b<=19; b++)
					{
						if(line[a]==line2[b]&&line[a]!=0)
						{
							result = line[a];
						}
					}
				}
				for(copy_step=0;copy_step<=19;copy_step++)
				{
					line[copy_step] = 0;
				}
				line[0] = result;
				printf("%d\n", result);
				show_line(line);
				fflush(stdin);
				printf("Delete?(Y/N)\n");
				scanf("%c", &delete_flag);
				if(delete_flag=='y'||delete_flag=='Y')
				{
					delete_lines(line);
					fflush(stdin);
					scanf ("%c" , &quit_flag);
				}
			}
		}
		else if(line[0]==0)
		{
			fflush(stdin);
			scanf ("%c" , &quit_flag);
		}
		break;
	case 2:
		search_number(true);
		if(line[1]==0 && line[0]!=0)
		{
			fflush(stdin);
			printf("Delete?(Y/N)\n");
			scanf("%c", &delete_flag);
			if(delete_flag=='y'||delete_flag=='Y')
			{
				delete_lines(line);
				fflush(stdin);
				scanf ("%c" , &quit_flag);
			}
		}
		else if(line[1]!=0 && line[0]!=0)
		{
			printf("search further?(Y/N)\n");
			fflush(stdin);
			scanf ("%c" , &search_further_flag);
			if(search_further_flag=='y'||search_further_flag=='Y')
			{
				for(copy_step=0;copy_step<=19;copy_step++)
				{
					line2[copy_step] = line[copy_step];
				}
				search_id(false);
				for(a=0 ; a<=19; a++)
				{
					for(b=0; b<=19; b++)
					{
						if(line[a]==line2[b]&&line[a]!=0)
						{
							result = line[a];
						}
					}
				}
				for(copy_step=0;copy_step<=19;copy_step++)
				{
					line[copy_step] = 0;
				}
				line[0] = result;
				printf("%d\n", result);
				show_line(line);
				fflush(stdin);
				printf("Delete?(Y/N)\n");
				scanf("%c", &delete_flag);
				if(delete_flag=='y'||delete_flag=='Y')
				{
					delete_lines(line);
					fflush(stdin);
					scanf ("%c" , &quit_flag);
				}
			}
		}
		else if(line[0]==0)
		{
			fflush(stdin);
			scanf ("%c" , &quit_flag);
		}
		break;
	case 3:
		now_task = main_menu;
		break;
	}
}

void main(void)
{
	while(1)
	{
		switch(now_task)
		{
		case main_menu:
			task_main_menu();
			break;

		case input_new_users:
			task_input_new_users();
			break;

		case show_users_messages:
			task_show_users_messages();
			break;

		case search_users:
			task_search_users();
			break;

		case delete_users:
			task_delete_users();
			break;
		}
	}
}

