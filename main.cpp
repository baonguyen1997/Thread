
//#include <bits/stdc++.h>
#include "baitap.h"
#include "sqlite3.h"
#include <cstring>
#include <string>
#include <list>
#include <sstream>
#include <ctime>
#include<conio.h>
#include<stdio.h>
#include <Thread>

#include <windows.h>
using namespace std;

int main(){
	User us ;
	int lc;
	int chon,a;
	bool kt = true , chinh = true;

	char c,c1,c2,c3;

	// in phong hiển thị lựa chon vào những thư mục rêng
	//system("cls");
	do{
		//system("cls");
	    us.nameuser();
		cout << "             <====================================================>\n\n";
		cout << "                        1 : quan ly nguoi dung \n";
		cout << "                        2 : qua ly tin nhan \n";
		cout << "                        3 : quan ly ban be \n";
		cout << "                        4 : thoat \n";
		cout << "     (Ctrl + B )<----------------------------------------------------> ( Ctrl + N)\n";
		
		c = _getch();
		//system("cls");
		do
		{
		switch (c)	{
		case 49:
			//system("cls");
			us.nameuser();
			cout << "           <====================================================>\n";
			cout << "                         1 : dang ky \n";
			cout << "                         2 : dang nhap \n";
			cout << "                         3 : dang xuat \n";
			cout << "                         4 : tro ve \n";
			cout << "     (Ctrl + B )<----------------------------------------------------> ( Ctrl + N)\n";
			
			c1 = _getch();
			switch (c1){
			case 49:{
					   us.SignUp();
					   break;
			}
			case 50:
			{
					  us.SignIn();
					  break;
			}
			case 51:
			{
					  cout << "da dang xuat \n";
					  us.SignOut();
					  break;
			}
			case 52:
				a = 49;
				chinh = false;
				system("cls");
				break;
			case 2:
				a = 49;
				chinh = false;
				system("cls");
				break;
			default: kt = true;
				break;
			}// ket thuc vong lap swith

			break;
		case 50:
		{
				//system("cls");
				  us.nameuser();
				  
				  cout << "             <====================================================>\n";
				  cout << "                        1 :hien thi cac tin nhan den\n";
				  cout << "                        2 :hien thi cac tin nhan da gui\n";
				  cout << "                        3 :giui tin nhan\n";
				  cout << "                        4 :thoat\n";
			      cout << "     (Ctrl + B )<----------------------------------------------------> ( Ctrl + N)\n";

				  c2 = _getch();
				  switch (c2)
				  {
				  case 49:
				  {
							//us.ShowMessdrec(us.id);
							thread ShowMe(&User::ShowMessdrec,us, us.id);
							if (ShowMe.joinable()){
								ShowMe.join();
							}
							break;

				  }
				  case 50:{
							// us.ShowMesssen(us.id);
							  thread ShowMesssen(&User::ShowMesssen, us, us.id);
							  if (ShowMesssen.joinable()){
								  ShowMesssen.join();
							// kt = true;
							  }
							  break;
				  }
				  case 51:{
						//	 us.SendMess(us.id);
							  thread SendMess(&User::SendMess, us, us.id);
							  if (SendMess.joinable()){
								  SendMess.join();
							  }
							  break;
				  }

				  case 52:{
							  a = 50;
							 chinh = false;
							 system("cls");
							 break;
				  }

				  case 2:{
							 a = 50;
							 chinh = false;
							  system("cls");
							  break;
				  }
				  default:
					  break;
				  }
				  break;
		}

		case 51:{
			//system("cls");
			 us.nameuser();
				   cout << "               <====================================================>\n";
				   cout << "                        1 : them ban be\n";
				   cout << "                        2 : hien thi danh sach ban be\n";
				   cout << "                        3 : danh sach block\n";
				   cout << "                        4: tro lai\n";
				   cout << "     (Ctrl + B )<----------------------------------------------------> ( Ctrl + N)\n";

				   int ban;
				   c3 = _getch();
				   switch (c3)
				   {
				   case 49:{
						    //  us.AddFriend(us.id);
							   thread AddFriend(&User::AddFriend, us, us.id);
							   if (AddFriend.joinable()){
								   AddFriend.join();
							   }
							   break;
				   }
				   case 50:
				   {
							// us.ShowFriend(us.id);
							  thread ShowFriend(&User::ShowFriend, us, us.id);
							  if (ShowFriend.joinable()){
								  ShowFriend.join();
							  }

							  break;
				   }
				   case 51:{
							//  us.BlockFriend(us.id);
							   thread BlockFriend(&User::BlockFriend, us, us.id);
							   if (BlockFriend.joinable()){
								   BlockFriend.join();
							   }
							   break;
				   }
				   case 52:
					   a = 51;
					   chinh = false;
					   system("cls");
					   break;
				   case 2:
					   a = 51;
					   chinh = false;
					   system("cls");
					   break;
				   default:
					   break;
				   }
				   break;
		}
		case 14:
		{		   chinh = true;
				   c = a;
				   cout << a;
				   break;
		}
		case 53:
		{		  
				us.Showcity(us.id);
				cout << "da nhan";
				   break;
		}
		case 52:
		{
				  cout << "hen gap lai dip khac \n";
				  kt = false;
				  return 0;
				  break;
		}

		default:kt = true;
			break;
		}
	} while (chinh);
	} while (kt);

	system("pause");
	return 0;
}
