#include<stdio.h>
 #include<conio.h>
 #include<graphics.h>
 #include<dos.h>
 #include<string.h>

  union REGS i,o;
 void login_window();
 void password_input();
 void draw_screen();
 void initialize_mouse();
 void show_mouse();
 void get_mouse();
 void add_window();
 void add_student_record();
 void search_student_record();
 void display_data();
 void delete_student_record();
 void modify_student_record();
 void list_records();
 void backup_database();
 void progress();
 void exit_system();

   struct ADDRESS
   {
    char STREET[25];
    char IM[25];
    char CITY[15];
    char COUNTRY[15];
    char  PIN[10];
    };

   struct STUDENT
   {
    int ROLL_NO;
    float MARKS;
    char MOBILE_NO[12];
    char F_NAME[20];
    char L_NAME[20];
    char COURSE_NAME[10];
    char SEX[7];
    char FEES[5];
    int DAY;
    int MONTH;
    int YEAR;

    struct ADDRESS A;

    };

 void main()
 {
    int gd=DETECT,gm;

    registerfarbgidriver(EGAVGA_driver_far);
    registerfarbgifont(sansserif_font_far);
    registerfarbgifont(small_font_far);
    registerfarbgifont(gothic_font_far);
    registerfarbgifont(triplex_font_far);

    initgraph(&gd,&gm,"C:\\turboc3\\bgi");

    login_window();
    password_input();
    start :

    cleardevice();

    draw_screen();
    initialize_mouse();

    setcolor(3);
    setfillstyle(1,8);
    rectangle(390,55,200,88);
    rectangle(395,50,195,94);
    floodfill(393,52,3);
    gotoxy(27,5);
    printf("1. ADD STUDENT RECORD ");

   /* FOLLOWING IS SEARCH RECORD */

    gotoxy(27,8);
    setcolor(3);
    setfillstyle(1,8);
    rectangle(390,135,200,105);
    rectangle(395,140,195,100);
    floodfill(394,139,3);
    printf("2. SEARCH RECORD ");

   /* FOLLOWING IS DELETE RECORD  */

    gotoxy(27,11);
    setcolor(3);
    setfillstyle(1,8);
    rectangle(390,180,200,152);
    rectangle(395,185,195,146);
    floodfill(394,184,3);
    printf("3. DELETE RECORD ");

   /* FOLLOWING COAD IS TO MODIFY RECORD */

    gotoxy(27,14);
    setcolor(3);
    setfillstyle(1,8);
    rectangle(390,229,200,199);
    rectangle(395,234,195,194);
    floodfill(394,233,3);
    printf("4. MODIFY RECORD ");

   /* FOLLOWING IS FOR LISTING RECORD  */

    gotoxy(27,17);
    setcolor(3);
    setfillstyle(1,8);
    rectangle(390,275,200,248);
    rectangle(395,282,195,242);
    floodfill(394,281,3);
    printf("5. LIST  RECORDS ");

   /* FOLLOWING COAD IS TO BEACKUP RECORDS */

    gotoxy(27,20);
    setcolor(3);
    rectangle(390,325,200,295);
    rectangle(395,330,195,290);
    floodfill(394,329,3);
    printf("6. BACKUP DATABASE ");

   /* FOLLOWING IS FOR EXITING SYSTEM  */

    gotoxy(27,23);
    setcolor(3);
    setfillstyle(1,8);
    rectangle(390,372,200,345);
    rectangle(395,377,195,340);
    floodfill(394,376,3);
    printf("7. EXIT SYSTEM ");

   show_mouse();

   while(!kbhit())
  {

  draw_screen();
  show_mouse();
  get_mouse();
  if(o.x.bx==1&&o.x.cx<395&&o.x.cx>195&&o.x.dx<94&&o.x.dx>50)
  {

   add_student_record();
   delay(500);
   goto start ;

  }

   if(o.x.bx==1&&o.x.cx<395&&o.x.cx>195&&o.x.dx<140&&o.x.dx>100)
   {
 search_student_record();
   goto start ;
      }

   if(o.x.bx==1&&o.x.cx<395&&o.x.cx>195&&o.x.dx<185&&o.x.dx>146)
   {
      delete_student_record();
      goto start ;
      }

   if(o.x.bx==1&&o.x.cx<395&&o.x.cx>195&&o.x.dx<234&&o.x.dx>194)
   {
      modify_student_record();
      goto start ;
      }

   if(o.x.bx==1&&o.x.cx<395&&o.x.cx>195&&o.x.dx<282&&o.x.dx>242)
   {
      list_records();
      delay(1000);
      goto start ;

      }

   if(o.x.bx==1&&o.x.cx<395&&o.x.cx>195&&o.x.dx<330&&o.x.dx>290)
    {
      backup_database();
      goto start ;
      }

   if(o.x.bx==1&&o.x.cx<395&&o.x.cx>195&&o.x.dx<377&&o.x.dx>340)
      exit_system();

    }

  getch();

 closegraph();

 }
 void login_window()
 {

  /* rectangle for password input */

    setcolor(3);
    setfillstyle(1,WHITE);
    rectangle(426,288,201,259);
    rectangle(425,287,202,260);
    floodfill(419,262,3);

    /* RECTANGLE FOR LOGO */

    setcolor(WHITE);
    setfillstyle(10,4);
    rectangle(402,142,224,222);
    rectangle(403,141,223,223);
    rectangle(404,140,222,224);
    floodfill( 400,218,WHITE);

    /* draws 1st body */

    setcolor(WHITE);
    setfillstyle(1,2);
    ellipse(270, 190, 0, 360,10, 18);
    ellipse(270, 190, 0, 360,11, 19);
    floodfill(271,191,WHITE);

    /* draws and fills 2nd body  */

    setfillstyle(1,2);
    ellipse(300, 195, 0, 360,10, 18);
    ellipse(300, 195, 0, 360,9, 17);
    floodfill(301,196,WHITE);

    /* draws 3rd body */

      setfillstyle(1,2);
      ellipse(320, 199, 0, 360,8, 12);
      ellipse(320, 199, 0, 360,7, 11);
      floodfill(321,200,WHITE);

    /* draw 4th body */

    setfillstyle(1,2);
    ellipse(340, 190, 0, 360,11, 25);
    ellipse(340, 190, 0, 360,10, 24);
    floodfill(341,191,WHITE);

    /* draws head for 1st body */

    setcolor(WHITE);
    setfillstyle(1,2);
    circle(270,152,9);
    circle(270,152,8);
    floodfill(271,153,WHITE);

   /* draws head for 2nd body */

    setcolor(WHITE);
    setfillstyle(1,2);
    circle(300,160,9);
    circle(300,160,8);
    floodfill(301,161,WHITE);

   /* draws a head for 3rd body */

     setcolor(WHITE);
     setfillstyle(1,2);
     circle(320,180,4);
     circle(320,180,3);
     floodfill(321,181,WHITE);

   /* draws head for 4th body */

    setcolor(WHITE);
    setfillstyle(1,2);
    circle(340,152,9);
    circle(340,152,8);
    floodfill(341,153,WHITE);

    gotoxy(23,16);
    printf("STUDENT DATABASE MANAGEMENT SYSTEM !");

    /* following coad is to draw the circle Enter Button */

    setcolor(WHITE);
    setfillstyle(1,4);
    circle(442,272,12);
    circle(442,272,11);
    circle(442,272,10);
    floodfill(442,272,WHITE);
    outtextxy(435,269,"->");
    setcolor(WHITE);
    circle(442,272,9);
    setbkcolor(0);
    gotoxy(15,15);
    setcolor(WHITE);
    settextstyle(1,0,1);
    outtextxy(512,98,"x");

    /* 510 for right side increaseo or decrease  /
       120 top increase decrease
       130 left increase decrease
       300 bottom increase decrease
       FOLLWING RECTANLGE JUST ABOVE INNERMOST RECTANGLE */

    setcolor(WHITE);
    rectangle(510,120,130,300);

    /* FOLLOWING IS COAD FOR INNER MOST RECTANGLE */

    setcolor(WHITE);
    setfillstyle(1,3);
    rectangle(531,100,112,321);
    floodfill(530,111,WHITE);

    /* FOLLOWING IS THE COAD FOR OUTERMOST WINDOW  */

    setcolor(8);
    setfillstyle(7,8);
    rectangle(532,99,111,322);
    rectangle(533,98,110,323);
    rectangle(534,97,109,324);
    rectangle(535,96,108,325);
    rectangle(536,95,107,326);
    rectangle(537,94,106,327);
    rectangle(538,93,105,328);
    rectangle(539,92,104,329);
    rectangle(540,91,103,328);
    floodfill(0,0,8);

  }

    void password_input()
  {
  int X=206,Y=262;
  char password[10];
  char pass[12]="dinesh";
  int i;
  char ch;
  for(i=0;i<12;i++)
  {
  ch=getch();
  password[i]=ch;
  if(ch==13)
  {
    password[i]='\0';
    delay(50);
    for(i=0;i<10;i++)
    {
    sound(99*i);
     /* following coad is to draw the circle Enter Button to give press effect  */
    setcolor(WHITE);
    setfillstyle(1,12);
    circle(442,272,12);
    circle(442,272,11);
    circle(442,272,10);
    floodfill(442,272,WHITE);
delay(19);
    setcolor(WHITE);
    setfillstyle(1,4);
    circle(442,272,12);
    circle(442,272,11);
    circle(442,272,10);
    floodfill(442,272,WHITE);
    nosound();

     }
     delay(1000);

  if(strcmp(pass,password)==0)
  {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");
    draw_screen();

    delay(1900); /* This dealy for pause thescreen for sometime.   */
    setcolor(15);
    setfillstyle(1,3);
    rectangle(460,249,140,180);
    rectangle(450,240,148,189);
    floodfill(451,241,15);

      for( i=0;i<10;i++)
    {

    sound(999);
    setcolor(0);
    outtextxy(220,210," ACEESS GRANTED ");
    delay(50);
    setcolor(15);
    outtextxy(220,210," ACEESS GRANTED ");
    nosound();

    }

     delay(1500); /*for pause the screen to sometime to display message. */
     break;

  }
  else
  {
   int gd=DETECT,gm, i;
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");
    draw_screen();

    delay(1400);
    setcolor(15);
    setfillstyle(1,3);
    rectangle(460,249,140,180);
    rectangle(450,240,148,189);
    floodfill(451,241,15);

  /* This for loop is for getting the sound effect */

    for( i=0;i<10;i++)
    {

    sound(999);
    setcolor(0);
    outtextxy(220,210," ACEESS DENIED ");
    delay(99);
    setcolor(15);
    outtextxy(220,210," ACEESS DENIED ");
    nosound();

     }

    delay(2000); /* for pause the screen to sometime to display message. */
    exit(1);

  }

  }

   /* following coad is to check whether the user press backslash or delete
      8 for ascii value of backspace  */

    if(ch==8)
    {
    i--;
    i--;
    X=X-15;
    fflush(stdin);

   /* The following is the restriction for * to print to backward side
      Otherwise the * is printed backward to input box */

    if(X<206)
   {
    X=206;
    }

    setcolor(15);
    settextstyle(2,0,7);
    outtextxy(X,Y,"*");
    X=X-15;
    nosound();

    }

    /* IF YOU PRESS ESC THEN EXITING THE SYSTEM */

    if(ch==27)
    exit_system();

    if(i>10)
    {
     sound(9999);

     }

    sound(800);
    setcolor(0);
    settextstyle(2,0,7);
    outtextxy(X,Y,"*");

    X=X+15;
    delay(100);
    nosound();

  }

  }

   void draw_screen()
   {

   setcolor(15);
   line(0,30,640,30);
   line(0,31,640,31);
   line(0,32,640,32);
   line(0,33,640,33);
   line(0,34,640,34);
   setfillstyle(1,3);
   floodfill(0,0,15);

  /* Bottom Horizontal line */

    setcolor(15);
    line(0,450,640,450);
    line(0,451,640,451);
    line(0,452,640,452);
    line(0,453,640,453);
    line(0,454,640,454);
    setfillstyle(1,3);
    floodfill(0,460,15);

   }
      void initialize_mouse()
   {

    i.x.ax=0;
    int86(0x33,&i,&o);

   }

   void show_mouse()
   {

    i.x.ax=1;
    int86(0x33,&i,&o);

   }

   void get_mouse()
   {

    i.x.ax=3;
    int86(0x33,&i,&o);

    }
  void add_window()
  {
    setcolor(3);
    settextstyle(12,0,1);
    outtextxy(110,50,"|||***** _ENTER STUDENT DATABASE MANUALLY_ *****|||");

  /* FOLLOWING COAD IS TO ADD RECORD/MODIFY */

    setcolor(3);  /* INTERNAL WINDOW */
    setfillstyle(1,8);
    rectangle(570,400,60,100);
    rectangle(571,401,59,99);
    setcolor(3);    /* OUTER WINDOW  */
    rectangle(590,420,40,80);
    rectangle(591,421,39,79);
    floodfill(579,418,3);

   }

 void add_student_record()
   {
      char INPUT ;
      struct STUDENT S;
      int gd=DETECT,gm;
      FILE *fp;
      initgraph(&gd,&gm,"C:\\turboc3\\bgi");
      cleardevice();
      draw_screen();
      add_window();
      fp=fopen("C:\\DATABASE.DAT","a");
      if(fp==NULL)
      {
      clrscr();
      printf("FILE OPENING ERROR ");
      delay(1000);
      exit(1);
      }
      fseek(fp,0,SEEK_END);
      fflush(stdin);
      INPUT='Y';
      while(INPUT=='Y'||INPUT=='y')
      {
      int gd=DETECT,gm;
      initgraph(&gd,&gm,"C:\\turboc3\\bgi");
      cleardevice();
      draw_screen();
      add_window();
      fflush(stdin);
      gotoxy(10,8);
      printf("ROLL NO OF STUDENT :: ");
      scanf("%d",&S.ROLL_NO);
      gotoxy(10,9);
      printf("ENTER FIRST NAME :: ");
      scanf("%s",S.F_NAME);
      gotoxy(10,10);
      printf("ENTER LAST NAME :: ");
      scanf("%s",S.L_NAME);
      gotoxy(10,11);
      printf(" SEX MALE OR FEMALE :: ");
      scanf("%s",S.SEX);
      gotoxy(10,12);
      printf(" COURSE NAME :: ");
      scanf("%s",S.COURSE_NAME);
      gotoxy(10,13);
      printf(" ADMISSION DATE DD/MM/YY FORMAT :: ");
      gotoxy(49,13);
      scanf("%d",&S.DAY);
      gotoxy(51,13);
      printf("/");
      gotoxy(53,13);
      scanf("%d",&S.MONTH);
      gotoxy(55,13);
      printf("/");
      gotoxy(56,13);
      scanf("%d",&S.YEAR);
      gotoxy(10,14);

      printf(" FEES STATUS [PAID OR DUE] :: ");
      scanf("%s",S.FEES);

      gotoxy(10,15);
      printf(" MARKS OF STUDENT :: ");
      scanf("%f",&S.MARKS);
      gotoxy(10,16);
    printf(" MOBILE NO. :: ");
    scanf("%s",S.MOBILE_NO);
    gotoxy(10,17);
    printf(" ADDRESS[STREET] :: ");
    scanf("%s",S.A.STREET);
    gotoxy(10,18);
    printf(" LAND MARK :: ");
    scanf("%s",S.A.IM);
    gotoxy(10,19);
    printf(" CITY :: ");
    scanf("%s",S.A.CITY);
    gotoxy(10,20);
    printf(" PIN :: ") ;
    scanf("%s",S.A.PIN);
    gotoxy(10,21);
    printf(" COUNTRY :: ");
    scanf("%s",S.A.COUNTRY);

    fwrite(&S,sizeof(S),1,fp);
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");
    cleardevice();
    draw_screen();
    gotoxy(20,14);
    setcolor(3);
    setfillstyle(1,8);
    rectangle(460,249,140,180);
    rectangle(450,240,148,189);
    floodfill(451,241,3);
    printf("ADD ANOTHER RECORD (YES/NO) ");
    fflush(stdin);
    INPUT=getch();
    }
    fclose(fp);

  }
  void search_student_record()
   {

    struct STUDENT S;
    int gd=DETECT,gm,RNO;
    FILE *fp;
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");

    cleardevice();
    draw_screen();

  /* FOLLOWING COAD PRINTS THE INPUT BOX FOR SEARCH RECORD/DELETE/MODIFY RECORD */

    setcolor(3);
    setfillstyle(1,8);
    rectangle(460,249,140,180);
    rectangle(450,240,148,189);
    floodfill(451,241,3);
    gotoxy(20,14);
    printf("ENTER ROLL NO :");
    scanf("%d",&RNO);

    fp=fopen("C:\\DATABASE.DAT","rb+");
    if(fp==NULL)
    {
    cleardevice();
    gotoxy(25,10);
    printf("FILE OPENING ERROR !");
    delay(1500);
    }
    while(fread(&S,sizeof(S),1,fp)==1)
    {
    if(strcmp(&S.ROLL_NO,&RNO)==0)
    {
    cleardevice();
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");
    draw_screen();
    display_data();

    gotoxy(10,8);
    printf("NAME :: %s ",S.L_NAME);
    gotoxy(28,8);
    printf("%s",S.F_NAME);
    gotoxy(10,10);
    printf("ROLL NO :: %d",S.ROLL_NO);
    gotoxy(35,10);
    printf("SEX :: %s",S.SEX);
    gotoxy(35,12);
    printf("ADMISSION DATE :: ");
    printf("%d/%d/%d",S.DAY,S.MONTH,S.YEAR);
    gotoxy(10,12);
    printf("COURSE_NAME :: %s",S.COURSE_NAME);
    gotoxy(10,14);
    printf("FEES STATUS :: %s",S.FEES);
    gotoxy(35,14);
    printf("MAKRS :: %f",S.MARKS);
    gotoxy(10,16);
    printf("MOBILE NO ::%s",S.MOBILE_NO);

    gotoxy(18,18);
    printf(" **************** ADDRESS ***************** ");
    gotoxy(10,20);
    printf("%s",S.A.STREET);
    gotoxy(10,21);
    printf("%s",S.A.IM);
    gotoxy(10,22);
    printf("%s",S.A.CITY);
    gotoxy(10,23);
    printf("%s",S.A.PIN);
    gotoxy(10,24);
    printf("%s",S.A.COUNTRY);
    delay(5000);
    break;
     }
    }
   }
    void display_data()
    {
      setcolor(3);
    settextstyle(12,0,1);
    outtextxy(145,50,"|||***** _DETAILS OF STUDENT_ *****|||");

  /* FOLLOWING COAD IS TO ADD RECORD/MODIFY */

    setcolor(3);  /* INTERNAL WINDOW  */
    setfillstyle(1,8);
    rectangle(570,400,60,100);
    rectangle(571,401,59,99);
    setcolor(3);    /* OUTER WINDOW */
    rectangle(590,420,40,80);
    rectangle(591,421,39,79);
    floodfill(579,418,3);
    }

     void delete_student_record()
   {
    int RNO;
    FILE *fp,*fp1;
    struct STUDENT S;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");
    cleardevice();
    draw_screen();

 /* FOLLOWING COAD PRINTS THE INPUT BOX FOR SEARCH RECORD/DELETE/MODIFY RECORD */

    setcolor(3);
    setfillstyle(1,8);
    rectangle(460,249,140,180);
    rectangle(450,240,148,189);
    floodfill(451,241,3);
    gotoxy(20,14);
    printf("ENTER ROLL NUMBER   :");
    scanf("%d",&RNO);
    fp=fopen("C:\\DATABASE.DAT","rb+");
    fp=fopen("C:\\TEMP.DAT","wb+");
    rewind(fp);
    while(fread(&S,sizeof(S),1,fp)==1)
    {
    if(strcmp(&S.ROLL_NO,&RNO)!=0)
    {
    fwrite(&S,sizeof(S),1,fp1);
    }
    }
    fclose(fp);
    fclose(fp1);
    remove("C:\\DATABASE.DAT");
    rename("C:\\TEMP.DAT","C:\\DATABASE.DAT");
    }

    void modify_student_record()
   {
    struct STUDENT S;
    FILE *fp;
    long int size=sizeof(S);
    char NAME[15];
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");
    cleardevice();
    draw_screen();

    /*   FOLLOWING COAD IS TO ADD RECORD/MODIFY  */

    setcolor(3);
    setfillstyle(1,8);
    rectangle(570,400,60,100);
    rectangle(571,401,59,99);
    setcolor(3);
    rectangle(590,420,40,80);
    rectangle(591,421,39,79);
    floodfill(579,418,3);

    /* FOLLOWING COAD PRINTS THE INPUT BOX FOR MODIFY RECORD */

    setcolor(3);
    setfillstyle(1,8);
    rectangle(460,249,140,180);
    rectangle(450,240,148,189);
    floodfill(451,241,3);
    gotoxy(20,14);

    printf("ENTER FIRST NAME :: ");
    scanf("%s",NAME);
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");
    cleardevice();
    draw_screen();
    add_window();

    fp=fopen("C:\\DATABASE.DAT","rb+");

    rewind(fp);
    while(fread(&S,sizeof(S),1,fp)==1)
    {
    if(strcmp(S.F_NAME,NAME)==0)
   {
    gotoxy(10,8);
    printf(" ROLL NO : ");
    scanf("%d",&S.ROLL_NO);
    gotoxy(10,9);
    printf(" FIRST NAME :: ");
    scanf("%s",S.F_NAME);
    gotoxy(10,10);
    printf(" LAST NAME :: ");
    scanf("%s",S.L_NAME);
    gotoxy(10,11);
    printf(" SEX MALE OR FEMALE :: ");
    scanf("%s",S.SEX);
    gotoxy(10,12);
    printf(" COURSE NAME :: ");
    scanf("%s",S.COURSE_NAME);
    gotoxy(10,13);
    printf(" ADMISSION DATE DD/MM/YY FORMAT :: ");
    gotoxy(49,13);
    scanf("%d",&S.DAY);
    gotoxy(51,13);
    printf("/");
    gotoxy(53,13);
    scanf("%d",&S.MONTH);
    gotoxy(55,13);
    printf("/");
    gotoxy(56,13);
    scanf("%d",&S.YEAR);
    gotoxy(10,14);
    printf("FEES STATUS PAID OR DUE :: ");
    scanf("%s",S.FEES);
    gotoxy(10,15);
    printf(" MARKS OF STUDENT :: ");
    scanf("%f",&S.MARKS);

    gotoxy(10,16);
    printf(" MOBILE NO. :: ");
    scanf("%s",S.MOBILE_NO);
    gotoxy(10,17);
    printf(" ADDRESS[STREET] :: ");
    scanf("%s",S.A.STREET);
    gotoxy(10,18);
    printf(" LAND MARK :: ");
    scanf("%s",S.A.IM);
    gotoxy(10,19);
    printf(" CITY :: ");
    scanf("%s",S.A.CITY);
    gotoxy(10,20);
    printf(" PIN :: ") ;

    scanf("%s",S.A.PIN);
    gotoxy(10,21);
    printf(" COUNTRY :: ");
    scanf("%s",S.A.COUNTRY);
    fseek(fp,-size,SEEK_CUR);
    fwrite(&S,size,1,fp);

}  /* END OF IF */
      }  /* END OF WHILE  */
    fclose(fp);

    }

   void list_records()
   {
    struct STUDENT S;
    FILE *fp;

  /* Y=6 for records to be printed along y-axis and goes increasing order 1by1 */

    int Y=6;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");
    cleardevice();
    draw_screen();

  /* FOLLOWING WINDOW IS FOR LIST RECORD  */

    setcolor(3);
    rectangle(610,448,21,40);
    rectangle(611,449,20,39);

  /* line to draw a horizontal above square. */

    line(20,65,610,65);
    line(21,66,611,66);

  /* ROLL NO COLUMN  */

    line(50,40,50,449);
    gotoxy(4,4);
    printf("NO.");

  /* NAME COLUMN */

    gotoxy(8,4);
    printf("NAME OF STUDENT");
    line(292,40,292,449);

  /* ADMISSION DATE */

    gotoxy(38,4);
    printf("ADM. DATE");
    line(380,40,380,449);

  /* COURSE NAME */

    gotoxy(49,4);
    printf("COURSE");
    line(440,40,440,449);

  /* FEES PAID OR NOT  */

    gotoxy(57,4);
    printf("FEES");
    line(500,40,500,449);

  /* THE REMAINING COLUMN IS FOR MOBILE NO */

    gotoxy(65,4);
    printf("MOBILE NO.");

    fp=fopen("C:\\DATABASE.DAT","rb+");
    rewind(fp);

   while(fread(&S,sizeof(S),1,fp)==1)
   {
    gotoxy(4,Y);
    printf("%d",S.ROLL_NO);
    gotoxy(8,Y);
    printf("%s",S.F_NAME);
    gotoxy(19,Y);
    printf("%s",S.L_NAME);
    gotoxy(38,Y);
    printf("%d/%d/%d",S.DAY,S.MONTH,S.YEAR);
    gotoxy(50,Y);
    printf("%s",S.COURSE_NAME);
    gotoxy(58,Y);
    printf("%s",S.FEES);
    gotoxy(66,Y);
    printf("%s",S.MOBILE_NO);
    Y++;
   }

    delay(10000);
    fclose(fp);

   }
     void backup_database()
   {
    struct STUDENT S;

    FILE *fp,*backup;
    fp=fopen("C:\\DATABASE.DAT","rb+");

    if(fp==NULL)
     {
     cleardevice();
     draw_screen();
     gotoxy(25,10);
    printf("FILE OPENING ERROR");
    delay(2000);
    exit(1);
     }

    backup=fopen("E:\\BACKUP.DAT","wb+");/* r+ because reads the existing content and write new contents */
  if(backup==NULL)
   {
    cleardevice();
    draw_screen();
    gotoxy(25,10);
    printf("FILE OPENING ERROR");
    delay(2500);
    exit(1);

    }
    progress();
    rewind(fp);
    while(fread(&S,sizeof(S),1,fp)==1)
    fwrite(&S,sizeof(S),1,backup);
    fclose(backup);
    fclose(fp);

    }

  void progress()
  {

    int gd=DETECT,gm,i;

    initgraph(&gd,&gm,"C:\\turboc3\\bgi");

    for( i=130;i<=495;i++)
    {
      draw_screen();
      setfillstyle(1,3);
      bar(i,255,150,265);
      sound(2*i);
      delay(9);

     }

    nosound();
    setcolor(15);
    gotoxy(12,12);
    outtextxy(200,240,"DATA BACKUP SUCCESSFULLY....");
    delay(5000);

     }

    void exit_system()
  {
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\turboc3\\bgi");
  cleardevice();
  draw_screen();
  gotoxy(12,10);
  printf("EXITING THE SYSTEM PLEASE WAIT ......");
  delay(1000);
  exit(0);

   }
