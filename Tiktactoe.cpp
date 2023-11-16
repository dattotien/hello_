 #include<bits/stdc++.h>
 using namespace std;
 #define fi first
 #define se second
 #define ll long long
 #define pii pair<int,int>
 #define si size()
 #define foe(i,a,b) for(int i=a;i<=b;i++)
 #define fol(i,a,b) for(int i=a;i<b;i++)
 // ▄▄▄   ▄▄ ▄▄▄ ▄▄▄ ▄▄▄
 //▄█▄ █ █▄▄█ █   █  █ █
 // █▄▄▀ █  █ █   █  █▄█
 /*    Normal Declaration   */
 /*    Algorithm implement  */
 /*        Main Code         */
char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
bool ans;
char current='X';
int row,column;
string player_1,player_2;
void print()
{
    cout<<"\n";
    cout<<"  |  |  \n";
    cout<<a[0][0]<<" |"<<a[0][1]<<" |"<<a[0][2]<<"\n";
    cout<<"__|__|__\n";
    cout<<"  |  |  \n";
    cout<<a[1][0]<<" |"<<a[1][1]<<" |"<<a[1][2]<<"\n";
    cout<<"__|__|__\n";
    cout<<"  |  |  \n";
    cout<<a[2][0]<<" |"<<a[2][1]<<" |"<<a[2][2]<<"\n";
    cout<<"  |  |  \n";
}
bool state()
{
    for(int i=0;i<3;i++)
    {
        if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]&&(a[i][0]=='X'||a[i][0]=='O'))
            return false;
        if(a[0][i]==a[1][i]&&a[1][i]==a[2][i]&&(a[0][i]=='X'||a[0][i]=='O'))
            return false;
    }
    if(a[0][0]!='1'&&a[0][0]==a[1][1]&&a[1][1]==a[2][2])return false;
    if(a[0][2]!='3'&&a[0][2]==a[1][1]&&a[1][1]==a[2][0])return false;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]!='X'&&a[i][j]!='O')
                return true;
        }
    }
    ans=true;
    return false;
}
void player_info()
{
    cout<<"Dien ten nguoi choi thu nhat: ";
    cin>>player_1;
    cout<<"\nDien ten nguoi choi thu hai: ";
    cin>>player_2;
    cout<<"\n"<<player_1<<" la X va se di truoc\n";
    cout<<"\n"<<player_2<<" la O va se di sau\n";
}
void Play()
{
    int num;
    do{
    cout<<"Hay chon o muon danh ";
    cin>>num;
    cout<<"\n";
    if(num==1)
    {
        row=0;
        column=0;
    }
    else if(num==2)
    {
        row=0;
        column=1;
    }
    else if(num==3)
    {
        row=0;
        column=2;
    }
    else if(num==4)
    {
        row=1;
        column=0;
    }
    else if(num==5)
    {
        row=1;
        column=1;
    }
    else if(num==6)
    {
        row=1;
        column=2;
    }
    else if(num==7)
    {
        row=2;
        column=0;
    }
    else if(num==8)
    {
        row=2;
        column=1;
    }
    else if(num==9)
    {
        row=2;
        column=2;
    }
    } while(num<1&&num>9);
    
}
void change()
{
    if(a[row][column]!='X'&&a[row][column]!='O'&&current=='X')
    {
        a[row][column]='X';
        current='O';
    }
    else if(a[row][column]!='X'&&a[row][column]!='O'&&current=='O')
    {
        a[row][column]='O';
        current='X';
    }
    else cout<<"O da duoc chon truoc do";
}
int main()
    {
        ans=false;
        player_info();
        print();
        while(state()==true)
        {
            Play();
            change();
            print();   
        }
        if(current=='X'&& ans==false)
            cout<<player_2<<" Win"<<endl;
        else if(current=='O'&& ans==false)
            cout<<player_1<<" Win"<<endl;
        else cout<<" Draw";

    } 
 