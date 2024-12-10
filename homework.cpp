#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <unistd.h>
using namespace std;

//学科科目类
class Subject
{
	public:
		string proName;  //学科名
		double proScore; //分数
		void showCpInfo()
		{
			cout << left << setw(43) << proName;
			cout << left << setw(6) <<  proScore << endl;
		}
		//输出属性名，只显示总积分
		static void showHeader()
		{
			cout << left << setw(45) << "科目";
			cout << left << setw(6) <<  "分数" <<endl;
		}
};
//学生类
class Student
{
	public:
		string stuNum;         //学号
		string stuName;        //姓名
		string gender;         //性别
		int gradeNum;          //年级
		string department;     //专业
		int classNum;          //班级
		vector<Subject> cps;  //学生的各个科目
		int cpNum;            //科目门数
		double score;         //平均分
		Student()
		{
		}
		Student(string stuNum, string stuName, string gender, int gradeNum, string department, int classNum,vector<Subject> cps, int cpNum, double score)
		{
			this->stuNum = stuNum;
			this->stuName = stuName;
			this->gender = gender;
			this->gradeNum = gradeNum;
			this->department = department;
			this->classNum = classNum;
			this->cps = cps;
			this->cpNum = cpNum;
			this->score = score;
		}
		~Student()
		{
		}
		//输出属性值  score是平均分
		virtual void showStuInfo()
		{
			cout << left << setw(10) << stuNum;
			cout << left << setw(8) <<  stuName;
			cout << left << setw(14) << gender;
			cout << left << setw(6) << gradeNum;
			cout << left << setw(21) << department;
			cout << left << setw(5) << classNum;
			cout << left << setw(6) << score << endl;
		}
		//输出属性名
		static void showHeader()
		{
			cout << left << setw(12) << "学号";
			cout << left << setw(10) <<  "姓名";
			cout << left << setw(8) << "性别" << "\t";
			cout << left << setw(8) << "年级";
			cout << left << setw(23) << "专业";
			cout << left << setw(6) << "班级" << "\t";
			cout << left << setw(6) << "平均分" << endl;
		}
};

class MyStudent : public Student{
public:
    double GPA_;
    MyStudent(){}
    MyStudent(string stuNum, string stuName, string gender, int gradeNum, string department, int classNum,vector<Subject> cps, int cpNum, double score, int GPA):Student(stuNum, stuName, gender, gradeNum, department, classNum, cps, cpNum, score){
        GPA_ = 0.0;
    }
    virtual void showStuInfo()
		{
			cout << left << setw(10) << stuNum;
			cout << left << setw(8) <<  stuName;
			cout << left << setw(14) << gender;
			cout << left << setw(6) << gradeNum;
			cout << left << setw(21) << department;
			cout << left << setw(5) << classNum;
			cout << left << setw(13) << score;
            cout << left << setw(8) << GPA_ << endl;
		}
    static void showHeader()
		{
			cout << left << setw(12) << "学号";
			cout << left << setw(10) <<  "姓名";
			cout << left << setw(8) << "性别" << "\t";
			cout << left << setw(8) << "年级";
			cout << left << setw(23) << "专业";
			cout << left << setw(6) << "班级" << "\t";
			cout << left << setw(16) << "平均分";
            cout << left << setw(8) << "GPA"<< endl;
		}
};
//学生列表类
class StudentList
{
	private:
		vector<MyStudent> stuList;
	public:
		StudentList()
		{
		}
		StudentList(vector<MyStudent> stuList)
		{
			this->stuList = stuList;
		}
		~StudentList()
		{
		}
		//初始化
		virtual void init()
		{
			readFile(); //读取文件
		}
		virtual void menu()
		{
			string sel = "0";
			system("cls");
			cout << "\t\t\t**********欢迎来到学生成绩管理系统**********" << endl;
			cout << "\t\t\t你可以进行以下操作:" << endl;
			cout << "\t\t\t|------------------------------------------|" << endl;
			cout << "\t\t\t|             1   添加学生信息             |" << endl;
			cout << "\t\t\t|------------------------------------------|" << endl;
			cout << "\t\t\t|             2   删除学生信息             |" << endl;
			cout << "\t\t\t|------------------------------------------|" << endl;
			cout << "\t\t\t|             3   修改学生信息             |" << endl;
			cout << "\t\t\t|------------------------------------------|" << endl;
			cout << "\t\t\t|             4   查询学生信息             |" << endl;
			cout << "\t\t\t|------------------------------------------|" << endl;
			cout << "\t\t\t|             5   显示信息列表             |" << endl;
			cout << "\t\t\t|------------------------------------------|" << endl;
			cout << "\t\t\t|             6   统计学生数据             |" << endl;
			cout << "\t\t\t|------------------------------------------|" << endl;
			cout << "\t\t\t|             7   清空系统数据             |" << endl;
			cout << "\t\t\t|------------------------------------------|" << endl;
			cout << "\t\t\t|             0   退出                     |" << endl;
			cout << "\t\t\t|------------------------------------------|" << endl;
			cout << "\t\t\t请选择【0-7】：";
			cin >> sel;
			while(sel != "0" && sel != "1" && sel != "2" && sel != "3" && sel != "4" && sel != "5" && sel != "6" && sel != "7")
			{
				cout << "\t\t\t输入不合法,请重新选择【0-7】：";
				cin >> sel;
			}
			if(sel == "1")
			{
				this->insertList();
				this->menu();
			}
			else if(sel == "2")
			{
				this->deleteList();
				this->menu();
			}
			else if(sel == "3")
			{
				this->updateList();
				this->menu();
			}
			else if(sel == "4")
			{
				this->selectList();
				this->menu();
			}
			else if(sel == "5")
			{
				this->displayList();
				this->menu();
			}
			else if(sel == "6")
			{
				this->statisticList();
				this->menu();
			}
			else if(sel == "7")
			{
				this->clearList();
				this->menu();
			}
			else if(sel == "0")
			{
				exit(0);
			}
		}
		//读取文件
		virtual void readFile()
		{
			ifstream ifs;
			ifs.open("/home/thomas/stuList.txt", ios::in);
			int n = 0; //用来接收学生数量的值
			ifs >> n;
			for(int i = 0; i < n; i++)
			{
				MyStudent s;
				ifs >> s.stuNum >> s.stuName >> s.gender >> s.gradeNum >> s.department >> s.classNum >> s.cpNum >> s.score >> s.GPA_;
				for(int j = 0; j < s.cpNum; j++)
				{
					Subject cp;
					ifs >> cp.proName >> cp.proScore;
					s.cps.push_back(cp);
				}
				stuList.push_back(s);
			}
			ifs.close();
		}
		//写入文件
		virtual void writeFile()
		{
			ofstream ofs;
			ofs.open("/home/thomas/stuList.txt", ios::out);
			ofs << stuList.size() << endl; //先写入学生数量
			for (int i = 0; i < stuList.size(); i++)
			{
				ofs << stuList[i].stuNum << " " <<  stuList[i].stuName << " " << stuList[i].gender
				    << " " << stuList[i].gradeNum << " " << stuList[i].department << " " << stuList[i].classNum
				    << " " << stuList[i].cpNum << " " << stuList[i].score << " " << stuList[i].GPA_ << endl;
				for(int j = 0; j < stuList[i].cps.size(); j++)
				{
					ofs << stuList[i].cps[j].proName << " " << stuList[i].cps[j].proScore << endl;
				}
			}
			ofs.close();
		}
		//添加学生信息
		virtual void insertList()
		{
			while(true)
			{
				system("cls");
				cout << "\t\t**********************欢迎来到添加学生信息功能*************************" << endl;
				cout<< "\t\t学生基本信息一览表："<<endl;
				displayStu();
				cout<<endl;
				cout << "\t\t------------------" << endl;
				cout << "\t\t1 添加学生信息" << endl;
				cout << "\t\t2 返回主菜单" << endl;
				cout << "\t\t------------------" << endl;
				cout << "\t\t请选择【1-2】：";
				string sel;
				cin >> sel;
				while(sel != "1" && sel != "2")
				{
					cout << "\t\t输入不合法,请重新输入【1-2】：";
					cin >> sel;
				}
				if(sel == "1")
				{
						cout << "\t\t输入学生信息："<<endl;
						cout << "\t\t学号：";
						MyStudent s;
						bool check = false;
						do
						{
							check = false;
							cin >> s.stuNum;
							for(int i = 0; i < stuList.size(); ++i)
							{
								if(s.stuNum == stuList[i].stuNum)
								{
									cout<<"\t\t该学号已存在，请重新输入：";
									check = true;
									break;
								}
							}
						}
						while(check);
						cout << "\t\t姓名：";
						cin >> s.stuName;
						cout << "\t\t性别：";
						cin >> s.gender;
						cout << "\t\t年级：";
						cin >> s.gradeNum;
						cout<<"\t\t专业：";
						cin >> s.department;
						cout<<"\t\t班级：";
						cin >> s.classNum;
						s.score = 0;
						string option = "1";
						cout<<"\t\t是否添加成绩信息？（1 是 0 否）"<<endl;
						cout << "\t\t请进行选择【0-1】：";
						cin >> option;
						while(option != "0" && option != "1")
						{
							cout << "\t\t输入不合法,请重新选择【0-1】：";
							cin >> option;
						}
						if(option == "1")
						{
							int cnt = 0;
							while(option == "1")
							{
								cnt++;
								Subject cp;
								cout<<"\t\t第"<<cnt<<"科科目名称：";
								cin>>cp.proName;
								cout<<"\t\t第"<<cnt<<"科科目成绩：";
								cin>>cp.proScore;
								s.cps.push_back(cp);
								cout << "\t\t该科成绩信息添加成功！是否继续添加？（1 是 0 否）" << endl;
								cout << "\t\t请进行选择【0-1】：";
								cin >> option;
								while(option != "0" && option != "1")
								{
									cout << "\t\t输入不合法,请重新选择【0-1】：";
									cin >> option;
								}
							}
						} 
						for(int i = 0; i < s.cps.size(); i++)
						{
							s.score += s.cps[i].proScore;
						}
						if(s.cps.size() > 0) s.score /= s.cps.size(); //计算平均分
                        s.GPA_ = (s.score - 50) / 10;
						s.cpNum = s.cps.size();
						stuList.push_back(s);
						writeFile();
				
					
					cout << "\t\t";
					pause();
				}
				else
				{
					break;
				}
			}
		}
		//删除学生信息
		virtual void deleteList()
		{
			while (true)
			{
				system("cls");
				cout << "\t\t***********************欢迎来到删除学生信息功能***********************" << endl;
				string sel = "0";
				cout << "\t\t-----------------" << endl;
				cout << "\t\t1 按学号删除" << endl;
				cout << "\t\t2 按姓名删除" << endl;
				cout << "\t\t3 返回主菜单" << endl;
				cout << "\t\t-----------------" << endl;
				cout << "\t\t请进行选择【1-3】：";
				cin >> sel;
				while(sel != "1" && sel != "2" && sel != "3")
				{
					cout << "\t\t输入不合法,请重新选择【1-3】：";
					cin >> sel;
				}
				if (sel == "1")
				{
					string keyNum;
					bool flag = false;
					cout << "\t\t请输入待删除学生的学号：";
					cin >> keyNum;
					for (vector<MyStudent>::iterator it = stuList.begin(); it != stuList.end(); ++it)
					{
						if (it->stuNum == keyNum)
						{
							flag = true;
							cout << "\t\t待删除学生的信息如下：" << endl;
							cout << "\t\t-----------------------------------------------------------------------" << endl;
							cout<<"\t\t";
							MyStudent::showHeader();
							cout << "\t\t-----------------------------------------------------------------------" << endl;
							cout<<"\t\t";
							it->showStuInfo();
							cout << "\t\t-----------------------------------------------------------------------" << endl;
							cout << "\t\t确认删除？（1 是 0 否）" << endl;
							cout << "\t\t请进行选择【0-1】：";
							string ch = "0";
							cin >> ch;
							while(ch != "0" && ch != "1")
							{
								cout << "\t\t输入不合法,请重新选择【0-1】：";
								cin >> ch;
							}
							if (ch == "0") break;
							else
							{
								stuList.erase(it);
								writeFile();
								cout << "\t\t删除成功！" << endl;
								break;
							}
						}
					}
					if (!flag) cout << "\t\t查无此人，无法删除！\n" << endl;
					cout << "\t\t";
					pause();
				}
				else if (sel == "2")
				{
					string keyName;
					bool flag = false;
					cout << "\t\t请输入待删除学生的姓名：";
					cin >> keyName;
					for (vector<MyStudent>::iterator it = stuList.begin(); it != stuList.end(); ++it)
					{
						if (it->stuName == keyName)
						{
							flag = true;
							cout << "\t\t待删除学生的信息如下：" << endl;
							cout << "\t\t-----------------------------------------------------------------------" << endl;
							cout<<"\t\t\t";
							MyStudent::showHeader();
							cout << "\t\t-----------------------------------------------------------------------" << endl;
							cout<<"\t\t";
							it->showStuInfo();
							cout << "\t\t-----------------------------------------------------------------------" << endl;
							cout << "\t\t确认删除？（1 是 0 否）" << endl;
							cout << "\t\t请进行选择【0-1】：";
							string ch = "0";
							cin >> ch;
							while(ch != "0" && ch != "1")
							{
								cout << "\t\t输入不合法,请重新选择【0-1】：";
								cin >> ch;
							}
							if (ch == "0") break;
							else
							{
								stuList.erase(it);
								writeFile();
								cout << "\t\t删除成功！" << endl;
								break;
							}
						}
					}
					if (!flag) cout << "\t\t查无此人，无法删除！\n" << endl;
					cout << "\t\t";
					pause();
				}
				else
				{
					break;
				}
			}
		}
		//修改学生信息
		virtual void updateList()
		{
			while(true)
			{
				system("cls");
				cout << "\t\t***********************欢迎来到修改学生信息功能***********************" << endl;
				string sel = "0";
				cout << "\t\t-----------------" << endl;
				cout << "\t\t1 修改学生基本信息" << endl;
				cout << "\t\t2 修改学生成绩信息" << endl;
				cout << "\t\t3 返回主菜单" << endl;
				cout << "\t\t-----------------" << endl;
				cout << "\t\t请进行选择【1-3】：";
				cin >> sel;
				while(sel != "1" && sel != "2" && sel != "3")
				{
					cout << "\t\t输入不合法,请重新选择【1-3】：";
					cin >> sel;
				}
 
				if(sel == "1")
				{
					bool flag = false;
					string keyNum;
					cout << "\t\t请输入待修改学生的学号：";
					cin >> keyNum;
					for (int i = 0; i < stuList.size(); i++)
					{
						if (stuList[i].stuNum == keyNum)
						{
							flag = true;
							cout << "\t\t待修改学生基本信息如下：" << endl;
							cout << "\t\t-----------------------------------------------------------------------" << endl;
							cout<<"\t\t";
							MyStudent::showHeader();
							cout << "\t\t-----------------------------------------------------------------------" << endl;
							cout<<"\t\t";
							stuList[i].showStuInfo();
							cout << "\t\t-----------------------------------------------------------------------" << endl;
							
							MyStudent s = stuList[i];
							cout << "\t\t请输入修改后的学号：";
							bool check = false;
							do
							{
								check = false;
								cin >> s.stuNum;
								for(int j = 0; j < stuList.size(); ++j)
								{
									if(s.stuNum == stuList[j].stuNum && i != j)
									{
										cout<<"\t\t该学号已被录入，请重新输入学号：";
										check = true;
										break;
									}
								}
							}
							while(check);
							cout << "\t\t请输入修改后的姓名：";
							cin >> s.stuName;
							cout << "\t\t请输入修改后的性别：";
							cin >> s.gender;
							cout << "\t\t请输入修改后的年级：";
							cin >> s.gradeNum;
							cout<<"\t\t请输入修改后的专业：";
							cin >> s.department;
							cout<<"\t\t请输入修改后的班级：";
							cin >> s.classNum;
							cout << "\t\t是否确认修改？（1 是 0 否）" << endl;
							cout << "\t\t请进行选择【0-1】：";
							string ch = "0";
							cin >> ch;
							while(ch != "0" && ch != "1")
							{
								cout << "\t\t输入不合法,请重新选择【0-1】：";
								cin >> ch;
							}
 
							if (ch == "0") break;
							else
							{
								stuList[i] = s;
								cout << "\t\t修改成功！" << endl;
								writeFile();
								break;
							}
						}
					}
					if (!flag) cout << "\t\t查无此人，无法修改！\n" << endl;
				}
				else if(sel == "2")
				{
					bool flag = false;
					string keyNum;
					cout << "\t\t请输入待修改学生的学号：";
					cin >> keyNum;
					for (int i = 0; i < stuList.size(); i++)
					{
						if (stuList[i].stuNum == keyNum)
						{
							flag = true;
							cout << "\t\t待修改学生成绩信息如下：" << endl;
							cout << "\t\t----------------------------------------------------------" << endl;
							cout<<"\t\t";
							cout << left << setw(6) <<  "编号";
							Subject::showHeader();
							cout << "\t\t----------------------------------------------------------" << endl;
							for(int j = 0; j < stuList[i].cps.size(); j++)
							{
								cout<<"\t\t";
								cout << left << setw(8) << j + 1;
								stuList[i].cps[j].showCpInfo();
							}
							cout << "\t\t----------------------------------------------------------" << endl;
							MyStudent s = stuList[i];
							cout << "\t\t请选择修改方式："<<endl;
							string option = "1";
							cout << "\t\t-------------------------------" << endl;
							cout << "\t\t1 基于该学生原有成绩信息进行修改" << endl;
							cout << "\t\t2 清空该学生所有科目及成绩信息" << endl;
							cout << "\t\t-------------------------------" << endl;
							cout << "\t\t请进行选择【1-2】：";
							cin >> option;
							while(option != "1" && option != "2")
							{
								cout << "\t\t输入不合法,请重新选择【1-2】：";
								cin >> option;
							}
							Subject cp;
							if(option == "1")
							{
								s.cps.clear();
								s.score = 0;
								s.cpNum = 0;
								cout<<"\t\t输入修改后的学科成绩信息："<<endl;
								int cnt = 0;
								while(option == "1")
								{
									cnt++;
									cout<<"\t\t第"<<cnt<<"科科目名称：";
									cin>>cp.proName;
									cout<<"\t\t第"<<cnt<<"科科目成绩：";
									cin>>cp.proScore;
									s.cps.push_back(cp);
									cout << "\n\t\t添加成功！是否继续添加？（1 是 0 否）" << endl;
									cout << "\t\t请进行选择【0-1】：";
									cin >> option;
									while(option != "0" && option != "1")
									{
										cout << "\t\t输入不合法,请重新选择【0-1】：";
										cin >> option;
									}
								}
							}
							else if(option == "2")
							{
								s.cps.clear();
								s.score = 0;
								s.cpNum = 0;
							}
							//计算平均分
							for(int i = 0; i < s.cps.size(); i++)
							{
								s.score += s.cps[i].proScore;
							}
                            
							if(s.cps.size() > 0) s.cpNum = s.cps.size();
                            s.score = s.score / s.cps.size();
                            s.GPA_ = (s.score - 50) / 10;
							cout << "\t\t是否确认修改？（1 是 0 否）" << endl;
							cout << "\t\t请进行选择【0-1】：";
							string ch = "0";
							cin >> ch;
							while(ch != "0" && ch != "1")
							{
								cout << "\t\t输入不合法,请重新选择【0-1】：";
								cin >> ch;
							}
							if (ch == "0") break;
							else
							{
								stuList[i] = s;
								cout << "\t\t修改成功！" << endl;
								writeFile();
								break;
							}
						}
					}
					if (!flag) cout << "\t\t查无此人，无法修改！\n" << endl;
				}
				else
				{
					break;
				}
				cout << "\t\t";
				pause();
			}
		}
		//查询学生信息
		virtual void selectList()
		{
			while (true)
			{
				system("cls");
				cout << "\t\t***********************欢迎来到查询学生信息功能************************" << endl;
				cout << "\t\t-----------------" << endl;
				cout << "\t\t1 按学号查询" << endl;
				cout << "\t\t2 按姓名查询" << endl;
				cout << "\t\t3 返回主菜单" << endl;
				cout << "\t\t-----------------" << endl;
				cout << "\t\t请进行选择【1-3】：";
				string sel = "0";
				cin >> sel;
				while(sel != "1" && sel != "2" && sel != "3")
				{
					cout << "\t\t输入不合法,请重新选择【1-3】：";
					cin >> sel;
				}
				if (sel == "1")
				{
					string keyNum;
					bool flag = false;
					cout << "\t\t请输入待查询学生的学号：";
					cin >> keyNum;
					cout << "\t\t查询结果如下：" << endl;
					cout<<"\t\t基本信息："<<endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout<<"\t\t";
					MyStudent::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					for (int i = 0; i < stuList.size(); i++)
					{
						if (stuList[i].stuNum == keyNum)
						{
							flag = true;
							cout<<"\t\t";
							stuList[i].showStuInfo();
							cout << "\t\t-----------------------------------------------------------------------" << endl;
							cout<<endl;
							cout<<"\t\t"<<stuList[i].stuName<<"成绩信息："<<endl;
							cout << "\t\t----------------------------------------------------------" << endl;
							cout<<"\t\t";
							cout << left << setw(8) <<  "编号";
							Subject::showHeader();
							cout << "\t\t----------------------------------------------------------" << endl;
							for(int j = 0; j < stuList[i].cps.size(); j++)
							{
								cout<<"\t\t";
								cout << left << setw(6) << j + 1;
								stuList[i].cps[j].showCpInfo();
							}
							cout << "\t\t----------------------------------------------------------" << endl;
							break;
						}
					}
					if (!flag) cout << "\t\t查无此人！\n" << endl;
					cout << "\t\t";
					pause();
				}
				else if (sel == "2")
				{
					string keyName;
					bool flag = false;
					cout << "\t\t请输入待查询联系人的姓名：";
					cin >> keyName;
					cout << "\t\t查询结果如下：" << endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout<<"\t\t";
					MyStudent::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					for (int i = 0; i < stuList.size(); i++)
					{
						if (stuList[i].stuName == keyName)
						{
							flag = true;
							cout<<"\t\t";
							stuList[i].showStuInfo();
							cout << "\t\t-----------------------------------------------------------------------" << endl;
							cout<<endl;
							cout<<"\t\t"<<stuList[i].stuName<<"成绩信息："<<endl;
							cout << "\t\t----------------------------------------------------------" << endl;
							cout<<"\t\t";
							cout << left << setw(8) <<  "编号";
							Subject::showHeader();
							cout << "\t\t----------------------------------------------------------" << endl;
							for(int j = 0; j < stuList[i].cps.size(); j++)
							{
								cout<<"\t\t";
								cout << left << setw(6) << j + 1;
								stuList[i].cps[j].showCpInfo();
							}
							cout << "\t\t----------------------------------------------------------" << endl;
							break;
						}
					}
					if (!flag) cout << "\t\t查无此人！\n" << endl;
					cout << "\t\t";
					pause();
				}
				else 
				{
					break; 
				}
			}
		}
		//遍历学生列表
		virtual void displayStu()
		{
			cout << "\t\t------------------------------------------------------------------------------------" << endl;
			cout<<"\t\t";
			MyStudent::showHeader();
			cout << "\t\t------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < stuList.size(); i++)
			{
				cout << "\t\t";
				stuList[i].showStuInfo();
			}
			cout << "\t\t------------------------------------------------------------------------------------" << endl;
		}
		//查询获奖信息
		virtual void displayCp()
		{
			cout << "\t\t-----------------------------------------------------------------------" << endl;
			cout<<"\t\t";
			cout << left << setw(12) << "学号";
			cout << left << setw(10) <<  "姓名";
			Subject::showHeader();
			cout << "\t\t-----------------------------------------------------------------------" << endl;
			for (int i = 0; i < stuList.size(); i++)
			{
				for(int j = 0; j < stuList[i].cps.size(); j++)
				{
					cout << "\t\t";
					cout << left << setw(10) << stuList[i].stuNum;
					cout << left << setw(8) <<  stuList[i].stuName;
					stuList[i].cps[j].showCpInfo();
				}
			}
			cout << "\t\t-----------------------------------------------------------------------" << endl;
		}
 
		//显示信息列表
		virtual void displayList()
		{
			system("cls");
			cout << "\t\t***********************欢迎来到显示信息列表功能************************" << endl;
			cout << "\t\t表1：学生基本信息一览表"<<endl;
			this->displayStu();
			cout << "\n\t\t表2：学生成绩信息一览表"<<endl;
			this->displayCp();
			cout << "\t\t";
			pause();
		}
		//将学生列表按学号升序排列
		static bool cmpNum(const MyStudent& s1,const MyStudent& s2)
		{
			return s1.stuNum < s2.stuNum;
		}
		//将学生列表按平均分降序排列，平均分相同的再按学号升序排列
		static bool cmpscore(const MyStudent& s1,const MyStudent& s2)
		{
			if(s1.stuNum != s2.stuNum) return s1.score > s2.score;
			else return s1.stuNum < s2.stuNum;
		}
		//统计学生数据
		virtual void statisticList()
		{
			while(true)
			{
				system("cls");
				cout << "\t\t***********************欢迎来到统计学生数据功能************************" << endl;
				string sel = "0";
				cout << "\t\t-----------------" << endl;
				cout << "\t\t1 按学号排序" << endl;
				cout << "\t\t2 按平均分排序" << endl;
				cout << "\t\t3 按GPA排序" << endl;
				cout << "\t\t4 返回主菜单" << endl;
				cout << "\t\t-----------------" << endl;
				cout << "\t\t请进行选择【1-4】：";
				cin >> sel;
				while(sel != "1" && sel != "2" && sel != "3"&& sel != "4")
				{
					cout << "\t\t输入不合法,请重新选择【1-4】：";
					cin >> sel;
				}
				if(sel == "1")
				{
					sort(stuList.begin(), stuList.end(), cmpNum);
					cout<<"\t\t按学号升序排列如下："<<endl;
					this->displayStu();
					int numMale = 0, numFemale = 0;
					for(int i = 0; i < stuList.size(); ++i)
					{
						if(stuList[i].gender == "男") numMale++;
						else if(stuList[i].gender == "女") numFemale++;
					}
					cout<<"\t\t一共 " << stuList.size() << " 人，其中男生 " << numMale << " 人，女生 " << numFemale << " 人。"<<endl;
					cout << "\t\t";
					pause();
				}
				else if(sel == "2")
				{
					sort(stuList.begin(), stuList.end(), cmpscore);
					cout<<"\t\t按平均分降序排列如下："<<endl;
					this->displayStu();
					vector<int> z(10);
					double totalscore = 0;
					for(int i = 0; i < stuList.size(); ++i)
					{
						totalscore += stuList[i].score;
						if(0 <= stuList[i].score && stuList[i].score < 60) z[0]++;
						else if(60 <= stuList[i].score && stuList[i].score < 70) z[1]++;
						else if(70 <= stuList[i].score && stuList[i].score < 80) z[2]++;
						else if(80 <= stuList[i].score && stuList[i].score < 90) z[3]++;
						else z[4]++;
					}
					cout<<"\t\tscore < 60 -------------- " << z[0] << " 人" << endl;
					cout<<"\t\t60 <= score < 70 --------- " << z[1] << " 人" << endl;
					cout<<"\t\t70 <= score < 80 --------- " << z[2] << " 人" << endl;
					cout<<"\t\t80 <= score < 90 --------- " << z[3] << " 人" << endl;
					cout<<"\t\tscore >= 90 ------------- " << z[4] << " 人" << endl;
					cout<<"\t\t所有学生平均分为："<<totalscore / stuList.size()<<endl;
					cout<<"\t\t"<<stuList.back().gradeNum<<"级"<<stuList.back().department<<stuList.back().classNum<<"班---";
					cout<<stuList.back().stuName<<"平均分最低，为："<<stuList.back().score<<"分"<<endl;
					cout<<"\t\t"<<stuList.front().gradeNum<<"级"<<stuList.front().department<<stuList.front().classNum<<"班---";
					cout<<stuList.front().stuName<<"平均分最高，为："<<stuList.front().score<<"分"<<endl;
					cout << "\t\t";
					pause();
				}
				else if(sel == "3")
				{
					sort(stuList.begin(), stuList.end(), cmpscore);
					cout<<"\t\t按GPA降序排列如下："<<endl;
					this->displayStu();
					pause();
            }
				else
				{
					break;
				}
			}
		}
		//清空系统数据
		virtual void clearList()
		{
			while (true)
			{
				string sel = "0";
				system("cls");
				cout << "\t\t**************欢迎来到清空系统数据功能***************" << endl;
				cout << "\t\t------------------" << endl;
				cout << "\t\t1 确认清空系统数据" << endl;
				cout << "\t\t2 返回主菜单" << endl;
				cout << "\t\t------------------" << endl;
				cout << "\t\t请慎重选择【1-2】：";
				cin >> sel;
				while(sel != "1" && sel != "2")
				{
					cout << "\t\t输入不合法,请重新输入【1-2】：";
					cin >> sel;
				}
				if (sel == "1")
				{
					stuList.clear();
					cout << "\t\t清空成功！" << endl;
					cout << "\t\t";
					pause();
					writeFile();
				}
				else 
				{
					break;
				}
			}
		}
};


int main()
{
	StudentList stuList;
	stuList.init(); //读入文件数据初始化
	stuList.menu(); //打开主菜单
	return 0;
}


