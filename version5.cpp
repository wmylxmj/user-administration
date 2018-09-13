#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//任务枚举
enum task{
	main_menu,
	input_new_users,
	show_users_messages,
	search_users,
	delete_users,
	exit_system,
	modify_users
};

typedef struct{
	char name[20];
	char sex[4];
	char age[3];
	char id[18];
	char number[11];
	char job[40];
	char address[40];
}user;

int now_task = main_menu;

/********************************主菜单显示函数*************************************/
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

/********************************搜索界面函数*************************************/
void search_menu()
{
	printf("\t\t\t\t\t☆☆☆☆☆☆☆信息查询☆☆☆☆☆☆☆\n\n");
	printf("\t\t\t\t\t            1.按用户名查询\n\n");
	printf("\t\t\t\t\t            2.按性别查询\n\n");
	printf("\t\t\t\t\t            3.按年龄查询\n\n");
	printf("\t\t\t\t\t            4.按身份证号查询\n\n");
	printf("\t\t\t\t\t            5.按手机号查询\n\n");
	printf("\t\t\t\t\t            6.按职业查询\n\n");
	printf("\t\t\t\t\t            7.按家庭住址查询\n\n");
	printf("\t\t\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
	printf("请输入你的选择：");
}

/********************************修改界面函数*************************************/
void modify_menu()
{
	printf("\t\t\t\t\t☆☆☆☆☆☆☆信息修改☆☆☆☆☆☆☆\n\n");
	printf("\t\t\t\t\t            1.用户名修改\n\n");
	printf("\t\t\t\t\t            2.性别修改\n\n");
	printf("\t\t\t\t\t            3.年龄修改\n\n");
	printf("\t\t\t\t\t            4.身份证号修改\n\n");
	printf("\t\t\t\t\t            5.手机号修改\n\n");
	printf("\t\t\t\t\t            6.职业修改\n\n");
	printf("\t\t\t\t\t            7.家庭住址修改\n\n");
	printf("\t\t\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
	printf("请输入你的选择：");
}

/********************************新增用户总任务函数********************************/
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

/********************************用户文件复制函数*************************************/
void file_copy(void)
{
	char job[40];
	char id[18];
	char name[20];
	char sex[4];
	char age[3];
	char address[40];
	char number[11];
	FILE*fp_w;
	fp_w=fopen("user_copy.txt","w");
	FILE*fp_r;
	fp_r=fopen("user.txt","r");
	while(!feof(fp_r))
	{
		//init
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
		if(strcmp(sex, "0")!=0)
		{
			fprintf(fp_w, "%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", name,sex,age,id,number,job,address);
		}
	}
	fclose(fp_r);
	fclose(fp_w);
}

/********************************删除某行函数*************************************/
void delete_line(int line)
{
	char job[40];
	char id[18];
	char name[20];
	char sex[4];
	char age[3];
	char address[40];
	char number[11];
	int i = 0;
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
		if(i==line)
		{
			write_flag = false;
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

/********************************用户显示总任务函数*************************************/
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

/********************************复制文件显示函数*************************************/
void show_messages_copy_file(void)
{
	char g;
	char ch;
	printf ("您选择的是用户信息浏览\n");
	printf ("当前用户信息\n");
	FILE*fp;//定义指向文件的指针变量
	fp=fopen("user_copy.txt","r");//打开文件并验证
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

/********************************用户查询函数*************************************/
void search(void)
{
	char job[40];
	char id[18];
	char name[20];
	char sex[4];
	char age[3];
	char address[40];
	char number[11];
	user search_user;
	int quit_count = 0;
	int quit_flag = false;
	int option;
	file_copy();
	while(!quit_flag)
	{
		system ("cls");
		printf("请增加查询条件\n");
		search_menu();
		FILE*fp_r;
		if((fp_r=fopen("user_copy.txt","r"))==NULL)
		{
			printf("cannot open file\n");
			exit(0);
		}
		FILE*fp_w;
		fp_w=fopen("user_copy_new.txt","w");
		fflush(stdin);
		scanf("%d", &option);
		switch(option)
		{
		case 1:
			quit_count = 0;	
			fflush(stdin);
			printf("please input name:\n");
			scanf("%s", search_user.name);
			while(!feof(fp_r))
			{
				//init
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
				if(strcmp(name,search_user.name)==0)
				{
					quit_count++;
					fprintf(fp_w, "%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", name,sex,age,id,number,job,address);
				}
			}
			fclose(fp_r);
			fclose(fp_w);
			if(remove("user_copy.txt"))
			{
				printf("Could not delete the file.\n");
			}
			else
			{
				printf("OK\n");
			}
			rename("user_copy_new.txt", "user_copy.txt");
			show_messages_copy_file();
			if(quit_count<=1)quit_flag = true;
			break;

		case 2:
			quit_count=0;
			fflush(stdin);
			printf("please input sex:\n");
			scanf("%s", search_user.sex);
			while(!feof(fp_r))
			{
				//init
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
				if(strcmp(sex,search_user.sex)==0)
				{
					quit_count++;
					fprintf(fp_w, "%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", name,sex,age,id,number,job,address);
				}
			}
			fclose(fp_r);
			fclose(fp_w);
			if(remove("user_copy.txt"))
			{
				printf("Could not delete the file.\n");
			}
			else
			{
				printf("OK\n");
			}
			rename("user_copy_new.txt", "user_copy.txt");
			show_messages_copy_file();
			if(quit_count<=1)quit_flag = true;
			break;

		case 3:
			quit_count=0;
			fflush(stdin);
			printf("please input age:\n");
			scanf("%s", search_user.age);
			while(!feof(fp_r))
			{
				//init
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
				if(strcmp(age,search_user.age)==0)
				{
					quit_count++;
					fprintf(fp_w, "%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", name,sex,age,id,number,job,address);
				}
			}
			fclose(fp_r);
			fclose(fp_w);
			if(remove("user_copy.txt"))
			{
				printf("Could not delete the file.\n");
			}
			else
			{
				printf("OK\n");
			}
			rename("user_copy_new.txt", "user_copy.txt");
			show_messages_copy_file();
			if(quit_count<=1)quit_flag = true;
			break;

		case 4:
			quit_count=0;
			fflush(stdin);
			printf("please input id:\n");
			scanf("%s", search_user.id);
			while(!feof(fp_r))
			{
				//init
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
				if(strcmp(id,search_user.id)==0)
				{
					quit_count++;
					fprintf(fp_w, "%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", name,sex,age,id,number,job,address);
				}
			}
			fclose(fp_r);
			fclose(fp_w);
			if(remove("user_copy.txt"))
			{
				printf("Could not delete the file.\n");
			}
			else
			{
				printf("OK\n");
			}
			rename("user_copy_new.txt", "user_copy.txt");
			show_messages_copy_file();
			if(quit_count<=1)quit_flag = true;
			break;

		case 5:
			quit_count=0;
			fflush(stdin);
			printf("please input number:\n");
			scanf("%s", search_user.number);
			while(!feof(fp_r))
			{
				//init
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
				if(strcmp(number,search_user.number)==0)
				{
					quit_count++;
					fprintf(fp_w, "%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", name,sex,age,id,number,job,address);
				}
			}
			fclose(fp_r);
			fclose(fp_w);
			if(remove("user_copy.txt"))
			{
				printf("Could not delete the file.\n");
			}
			else
			{
				printf("OK\n");
			}
			rename("user_copy_new.txt", "user_copy.txt");
			show_messages_copy_file();
			if(quit_count<=1)quit_flag = true;
			break;

		case 6:
			quit_count=0;
			fflush(stdin);
			printf("please input job:\n");
			scanf("%s", search_user.job);
			while(!feof(fp_r))
			{
				//init
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
				if(strcmp(job,search_user.job)==0)
				{
					quit_count++;
					fprintf(fp_w, "%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", name,sex,age,id,number,job,address);
				}
			}
			fclose(fp_r);
			fclose(fp_w);
			if(remove("user_copy.txt"))
			{
				printf("Could not delete the file.\n");
			}
			else
			{
				printf("OK\n");
			}
			rename("user_copy_new.txt", "user_copy.txt");
			show_messages_copy_file();
			if(quit_count<=1)quit_flag = true;
			break;

		case 7:
			quit_count=0;
			fflush(stdin);
			printf("please input address:\n");
			scanf("%s", search_user.address);
			while(!feof(fp_r))
			{
				//init
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
				if(strcmp(address,search_user.address)==0)
				{
					quit_count++;
					fprintf(fp_w, "%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", name,sex,age,id,number,job,address);
				}
			}
			fclose(fp_r);
			fclose(fp_w);
			if(remove("user_copy.txt"))
			{
				printf("Could not delete the file.\n");
			}
			else
			{
				printf("OK\n");
			}
			rename("user_copy_new.txt", "user_copy.txt");
			show_messages_copy_file();
			if(quit_count<=1)quit_flag = true;
			break;
		}
	}
}

/********************************用户查询总任务函数*************************************/
void task_search_users(void)
{
	search();
}

/********************************用户查询寻找行函数*************************************/
int find_line_of_user_searched(void)
{
	char user_searched_job[40];
	char user_searched_id[18];
	char user_searched_name[20];
	char user_searched_sex[4];
	char user_searched_age[3];
	char user_searched_address[40];
	char user_searched_number[11];
	char now_user_job[40];
	char now_user_id[18];
	char now_user_name[20];
	char now_user_sex[4];
	char now_user_age[3];
	char now_user_address[40];
	char now_user_number[11];
	int line = 0;
	FILE*fp_c;
	fp_c=fopen("user_copy.txt","r");
	FILE*fp_u;
	fp_u=fopen("user.txt","r");
	//init
	strcpy(user_searched_name, "0");
	strcpy(user_searched_sex, "0");
	strcpy(user_searched_age, "0");
	strcpy(user_searched_id, "0");
	strcpy(user_searched_number, "0");
	strcpy(user_searched_job, "0");
	strcpy(user_searched_address, "0");
	fscanf(fp_c,"%s",user_searched_name);
	fscanf(fp_c,"%s",user_searched_sex);
	fscanf(fp_c,"%s",user_searched_age);
	fscanf(fp_c,"%s",user_searched_id);
	fscanf(fp_c,"%s",user_searched_number);
	fscanf(fp_c,"%s",user_searched_job);
	fscanf(fp_c,"%s",user_searched_address);
	fclose(fp_c);
	while(!feof(fp_u))
	{
		//init
		strcpy(now_user_name, "0");
		strcpy(now_user_sex, "0");
		strcpy(now_user_age, "0");
		strcpy(now_user_id, "0");
		strcpy(now_user_number, "0");
		strcpy(now_user_job, "0");
		strcpy(now_user_address, "0");
		fscanf(fp_u,"%s",now_user_name);
		fscanf(fp_u,"%s",now_user_sex);
		fscanf(fp_u,"%s",now_user_age);
		fscanf(fp_u,"%s",now_user_id);
		fscanf(fp_u,"%s",now_user_number);
		fscanf(fp_u,"%s",now_user_job);
		fscanf(fp_u,"%s",now_user_address);
		line++;
		if(strcmp(now_user_name,user_searched_name)==0&&
			strcmp(now_user_sex,user_searched_sex)==0&&
			strcmp(now_user_age,user_searched_age)==0&&
			strcmp(now_user_id,user_searched_id)==0&&
			strcmp(now_user_number,user_searched_number)==0&&
			strcmp(now_user_job,user_searched_job)==0&&
			strcmp(now_user_address,user_searched_address)==0)
		{
			fclose(fp_u);
			return line;
		}
	}
	fclose(fp_u);
	return 0;
}

/********************************删除用户总任务函数*************************************/
void task_delete_users(void)
{
	char quit;
	int line;
	char answer;
	search();
	printf("Delete?(Y/N)\n");
	fflush(stdin);
	scanf("%c", &answer);
	if(answer=='y'||answer=='Y')
	{
		line = find_line_of_user_searched();
		delete_line(line);
		printf("finished!\n");
		fflush(stdin);
		scanf("%c", &quit);
		now_task = main_menu;
	}
	else
	{
		now_task = main_menu;
	}
}

/********************************主菜单总任务函数*************************************/
void task_main_menu(void)
{
	int g;
	system ("color b1");
	system("cls");
	show_main_menu();	
	scanf("%d",&g);
	switch(g)
	{
	case 1:
		now_task = input_new_users;
		break;

	case 2:
		now_task = show_users_messages;
		break;
	
	case 3:
		now_task = modify_users;
		break;

	case 4:
		now_task = delete_users;
		break;

	case 5:
		now_task = search_users;
		break;

	case 6:
		now_task = exit_system;
		break;

	default:
		now_task = main_menu;
		break;

	}
}

/********************************退出系统总任务函数*************************************/
void task_exit_system(void)
{
	exit(0);
}

/********************************修改信息总任务函数*************************************/
void task_modify_users(void)
{
	char user_searched_job[40];
	char user_searched_id[18];
	char user_searched_name[20];
	char user_searched_sex[4];
	char user_searched_age[3];
	char user_searched_address[40];
	char user_searched_number[11];
	char quit;
	bool sure_flag = false;
	char answer;
	int option;
	int line = 0;
	search();
	FILE*fp_c;
	fp_c=fopen("user_copy.txt","r");
	//init
	strcpy(user_searched_name, "0");
	strcpy(user_searched_sex, "0");
	strcpy(user_searched_age, "0");
	strcpy(user_searched_id, "0");
	strcpy(user_searched_number, "0");
	strcpy(user_searched_job, "0");
	strcpy(user_searched_address, "0");
	fscanf(fp_c,"%s",user_searched_name);
	fscanf(fp_c,"%s",user_searched_sex);
	fscanf(fp_c,"%s",user_searched_age);
	fscanf(fp_c,"%s",user_searched_id);
	fscanf(fp_c,"%s",user_searched_number);
	fscanf(fp_c,"%s",user_searched_job);
	fscanf(fp_c,"%s",user_searched_address);
	fclose(fp_c);
	while(!sure_flag)
	{
		if(strcmp(user_searched_sex, "0")==0)
		{
			break;
		}
		system("cls");
		modify_menu();
		fflush(stdin);
		scanf("%d", &option);
		switch(option)
		{
		case 1:
			printf("your new name:\n");
			fflush(stdin);
			scanf("%s", user_searched_name);
			printf("any other to modify?\n(Y/N)");
			fflush(stdin);
			scanf("%c", &answer);
			if(answer=='n'||answer=='N')
			{
				sure_flag = true;
			}
			break;

		case 2:
			printf("your new sex:\n");
			fflush(stdin);
			scanf("%s", user_searched_sex);
			printf("any other to modify?\n(Y/N)");
			fflush(stdin);
			scanf("%c", &answer);
			if(answer=='n'||answer=='N')
			{
				sure_flag = true;
			}
			break;

		case 3:
			printf("your new age:\n");
			fflush(stdin);
			scanf("%s", user_searched_age);
			printf("any other to modify?\n(Y/N)");
			fflush(stdin);
			scanf("%c", &answer);
			if(answer=='N'||answer=='n')
			{
				sure_flag = true;
			}
			break;

		case 4:
			printf("your new id:\n");
			fflush(stdin);
			scanf("%s", user_searched_id);
			printf("any other to modify?\n(Y/N)");
			fflush(stdin);
			scanf("%c", &answer);
			if(answer=='n'||answer=='N')
			{
				sure_flag = true;
			}
			break;

		case 5:
			printf("your new number:\n");
			fflush(stdin);
			scanf("%s", user_searched_number);
			printf("any other to modify?\n(Y/N)");
			fflush(stdin);
			scanf("%c", &answer);
			if(answer=='n'||answer=='N')
			{
				sure_flag = true;
			}
			break;

		case 6:
			printf("your new job:\n");
			fflush(stdin);
			scanf("%s", user_searched_job);
			printf("any other to modify?\n(Y/N)");
			fflush(stdin);
			scanf("%c", &answer);
			if(answer=='N'||answer=='n')
			{
				sure_flag = true;
			}
			break;

		case 7:
			printf("your new address:\n");
			fflush(stdin);
			scanf("%s", user_searched_address);
			printf("any other to modify?\n(Y/N)");
			fflush(stdin);
			scanf("%c", &answer);
			if(answer=='N'||answer=='n')
			{
				sure_flag = true;
			}
			break;
		}
	}
	if(strcmp(user_searched_sex, "0")!=0)
	{
		line = find_line_of_user_searched();
		delete_line(line);
		FILE*fp;
		fp=fopen("user.txt","a+");
		fprintf(fp, "%-20s\t%-4s\t%-3s\t%-18s\t%-11s\t%-40s\t%-40s\t\n", 
			user_searched_name,user_searched_sex,user_searched_age,user_searched_id,user_searched_number,user_searched_job,user_searched_address);
		fclose(fp);
		printf("finished!\n");
		fflush(stdin);
		scanf("%c", &quit);
	}
	now_task = main_menu;
}

/********************************主函数*************************************/
//状态机
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

		case exit_system:
			task_exit_system();
			break;

		case modify_users:
			task_modify_users();
			break;
		}
	}
}
