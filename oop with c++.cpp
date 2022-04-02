#include<iostream>//\n ||
#include<string.h>
#include<string>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<vector>
using namespace std;
bool logineditor()
{
    string s="editor";
    string id;
    string p="7kingdoms";
    string pass;
    int login=0;
    do
    {
        cout<<"Enter your id: ";
        cin>>id;
        cout<<"Enter password: ";
        cin>>pass;
        if(s==id && p==pass)
        {
            login++;
            cout<<"Login Successful"<<endl;
            return true;
        }
        else
        {
            cout<<"Incorrect id or password.Please try again."<<endl;
        }
    }
    while(login==0);
}
class User
{
private:
    string userid;
    string userpass;
public:
    void registerid();
    void loginUser();
    bool login_verify();
};
void User::registerid()
{
    fstream fout;
    fout.open("register id&pass.csv",ios::app);
    cout<<"___REGISTER AN ACCOUNT HERE___"<<endl;
    cout<<"Enter UserID: ";
    cin>>userid;
    cout<<"Enter Password: ";
    cin>>userpass;
    if(login_verify())
    {
        fout<<userid<<","<<userpass<<"\n";
        fout.close();
        cout<<"You Are Now Registered And Logged In Successfully"<<endl;
    }
    else
    {
        registerid();
    }
}
void User::loginUser()
{
    fstream fin;
    fin.open("register id&pass.csv",ios::in);
    string i,p;
    cout<<"Enter your UserID: ";
    cin>>i;
    cout<<"Enter your Password: ";
    cin>>p;
    int c=0;
    vector<string>row;
    string line,word;
    while(getline(fin,line))
    {
        row.clear();
        stringstream s(line);
        while(getline(s,word,','))
        {
            row.push_back(word);
        }
        if(i==row[0] && p==row[1])
        {
            c=1;
            cout<<"Login Successful.\n";
            fin.close();
            break;
        }

    }
    if(c!=1)
    {
        cout<<"You are not registered."<<endl;
        fin.close();
        registerid();
    }

}
bool User::login_verify()
{
    fstream fin;
    fin.open("register id&pass.csv",ios::in);
    int c=0;
    vector<string>row;
    string line,word;
    while(getline(fin,line))
    {
        row.clear();
        stringstream s(line);
        while(getline(s,word,','))
        {
            row.push_back(word);
        }
        if(userid==row[0])
        {
            c=1;
            cout<<"This username already exists.Try again\n";
            fin.close();
            return false;
        }
    }
    return true;
}
class House
{
private:
    char s[200];
    int member;
public:
    void stark()
    {
        strcpy(s,"_____HOUSE DETAILS______\nHouse Stark of Winterfell\nSigil:A grey direwolf on a white field.\nWords:Winter is coming");
        member = 5;
        cout<<s<<endl;
        cout<<"Members included here: "<<member<<endl;
    }
    void targaryen()
    {
        strcpy(s,"_____HOUSE DETAILS______\nHouse Targaryen of Dragonstone\nSigil:Three headed red dragon on a black background.\nWords:Fire and blood.");
        member = 5;
        cout<<s<<endl;
        cout<<"Members included here: "<<member<<endl;
    }
    void Lannister()
    {
        strcpy(s,"_____HOUSE DETAILS______\nHouse Lannister of Casterly Rock\nSigil:A golden lion on a crimson field.\nWords:Hear me roar");
        member=3;
        cout<<s<<endl;
        cout<<"Members included here: "<<member<<endl;
    }
    virtual void read_record(string)=0;
};
class character:public House
{
    string name;
    int age;
public:
    character() {}
    character(string s,int a)
    {
        name=s;
        age=a;
    }
    void file_write();
    void read_record(string in);
    friend ostream & operator <<(ostream &,character &);
};
void character::file_write()
{
    fstream fout;
    fout.open("character details.csv",ios::out);
    fout<<"ned"<<","<<"Former lord of Winterfell."<<",   "
        <<"Status: deceased."<<",   "<<"died in season 1.\n";
    fout<<"robb"<<","<<"King in the North."<<",   "
        <<"Status: deceased."<<",   "<<"died in season 3.\n";
    fout<<"sansa"<<","<<"Queen in"<<", "<<"the North."<<",   "
        <<"Status: Alive.\n";
    fout<<"arya"<<","<<"Killed the Night King."<<",   "<<"Has set sail to the West of Westeros."<<",   "
        <<"Status: Alive.\n";
    fout<<"bran"<<","<<"King of the Six Kingdoms"<<", "<<"and Three-eyed raven."<<",   "
        <<"Status: Alive.\n";
    fout<<"aerys"<<","<<"Popularly called the Mad-King."<<",   "
        <<"Status: deceased."<<",   "<<"killed by Jaime Lannister.\n";
    fout<<"rhaegar"<<","<<"Known as the last Dragon."<<",   "
        <<"Status: deceased."<<",   "<<"died at Battle-of-the-Trident.\n";
    fout<<"viserys"<<","<<"Younger brother of Rhaegar."<<",   "
        <<"Status: deceased."<<",   "<<"Killed by Khal Drogo.\n";
    fout<<"daenerys"<<","<<"Mother of Dragons the Unburnt"<<", "<<"and Breaker of chains."<<",   "
        <<"Status: deceased.\n";
    fout<<"cersei"<<","<<"Queen Regent."<<",   "
        <<"Status: deceased."<<",   "<<"Killed and buried under the Red Keep.\n";
    fout<<"jaime"<<","<<"Former Lord-Commander of the Kingsguard."<<",   "
        <<"Status: deceased."<<",   "<<"Killed and buried under the Red Keep.\n";
    fout<<"tyrion"<<","<<"Dwarf of the Casterly Rock."<<",   "
        <<"Hand of the King of King Bran Stark."<<",   "<<"Status: Alive.\n";
    fout<<"jon"<<","<<"Real name is Aegon Targaryen."<<",   "
        <<"Heir to the Iron Throne."<<",   "<<"Status: Alive and exiled.\n";
    fout.close();
}
void character::read_record(string in)
{
    fstream fin;
    fin.open("character details.csv",ios::in);
    int c=0;
    string r;
    cout<<"____CHARACTER DETAILS____"<<endl;
    vector<string>row;
    string line,word;
    while(getline(fin,line))
    {
        row.clear();
        stringstream s(line);
        while(getline(s,word,','))
        {
            row.push_back(word);
        }
        r=row[0];
        if(r==in)
        {
            c++;
            cout<<row[1]<<row[2]<<row[3]<<endl;
            break;
        }
    }
    if(c!=1)
        cout<<"record not found"<<endl;
    fin.close();
}
ostream & operator<<(ostream &dout,character &c)
{
    dout<<"Name: "<<c.name<<endl;
    dout<<"Age: "<<c.age<<endl;
    return dout;
}
class Episodes
{
public:
    int s,e;
    void episode_name();
    friend void episode_delete();
    friend void read_episodes(Episodes);
    void getdata()
    {
        int a,b;
        cout<<"Season: ";
        cin>>a;
        cout<<"Episode: ";
        cin>>b;
        s=a;
        e=b;
    }
};
void Episodes::episode_name()
{
    fstream fout;
    fout.open("episode name.csv",ios::out);
    fout<<"1"<<","<<"1"<<","<<"Winter Is Coming\n";
    fout<<"1"<<", "<<"2"<<","<<"The Kingsroad\n";
    fout<<"1"<<", "<<"3"<<","<<"Lord Snow\n";
    fout<<"1"<<", "<<"4"<<","<<"Cripples Bastards and Broken Things\n";
    fout<<"1"<<", "<<"5"<<","<<"The Wolf and the Lion\n";
    fout<<"1"<<", "<<"6"<<","<<"A Golden Crown\n";
    fout<<"1"<<", "<<"7"<<","<<"You Win or You Die\n";
    fout<<"1"<<", "<<"8"<<","<<"The Pointy End\n";
    fout<<"1"<<", "<<"9"<<","<<"Baelor\n";
    fout<<"1"<<", "<<"10"<<","<<"Fire and Blood\n";

    fout<<"2"<<", "<<"1"<<","<<"The North Remembers\n";
    fout<<"2"<<", "<<"2"<<","<<"The Night Lands\n";
    fout<<"2"<<", "<<"3"<<","<<"What Is Dead May Never Die\n";
    fout<<"2"<<", "<<"4"<<","<<"Garden of Bones\n";
    fout<<"2"<<", "<<"5"<<","<<"The Ghost of Harrenhal\n";
    fout<<"2"<<", "<<"6"<<","<<"The Old Gods and the New\n";
    fout<<"2"<<", "<<"7"<<","<<"A Man Without Honour\n";
    fout<<"2"<<", "<<"8"<<","<<"The Prince of Winterfell\n";
    fout<<"2"<<", "<<"9"<<","<<"Blackwater\n";
    fout<<"2"<<", "<<"10"<<","<<"Valar Morghulis\n";

    fout<<"3"<<", "<<"1"<<","<<"Valar Dohaeris\n";
    fout<<"3"<<", "<<"2"<<","<<"Dark Wings Dark Words\n";
    fout<<"3"<<", "<<"3"<<","<<"Walk of Punishment\n";
    fout<<"3"<<", "<<"4"<<","<<"And Now His Watch Ended\n";
    fout<<"3"<<", "<<"5"<<","<<"Kissed by Fire\n";
    fout<<"3"<<", "<<"6"<<","<<"The Climb\n";
    fout<<"3"<<", "<<"7"<<","<<"The Bear and the Maiden Fair\n";
    fout<<"3"<<", "<<"8"<<","<<"Second Sons\n";
    fout<<"3"<<", "<<"9"<<","<<"The Rains of Castamere\n";
    fout<<"3"<<", "<<"10"<<","<<"Mhysa\n";

    fout<<"4"<<", "<<"1"<<","<<"Two Swords\n";
    fout<<"4"<<", "<<"2"<<","<<"The Lion and the Rose\n";
    fout<<"4"<<", "<<"3"<<","<<"Breaker Of Chains\n";
    fout<<"4"<<", "<<"4"<<","<<"Oathkeeper\n";
    fout<<"4"<<", "<<"5"<<","<<"First of His Name\n";
    fout<<"4"<<", "<<"6"<<","<<"The Laws of Gods and Men\n";
    fout<<"4"<<", "<<"7"<<","<<"Mockingbird\n";
    fout<<"4"<<", "<<"8"<<","<<"The Mountain and the Viper\n";
    fout<<"4"<<", "<<"9"<<","<<"The Watchers on the Wall\n";
    fout<<"4"<<", "<<"10"<<","<<"The Children\n";

    fout<<"5"<<", "<<"1"<<","<<"The Wars to Come\n";
    fout<<"5"<<", "<<"2"<<","<<"The House of Black and White\n";
    fout<<"5"<<", "<<"3"<<","<<"High Sparrow\n";
    fout<<"5"<<", "<<"4"<<","<<"Sons of the Harpy\n";
    fout<<"5"<<", "<<"5"<<","<<"Kill the boy\n";
    fout<<"5"<<", "<<"6"<<","<<"Unbowed Unbent Unbroken\n";
    fout<<"5"<<", "<<"7"<<","<<"The Gift\n";
    fout<<"5"<<", "<<"8"<<","<<"Hardhome\n";
    fout<<"5"<<", "<<"9"<<","<<"The Dance of Dragons\n";
    fout<<"5"<<", "<<"10"<<","<<"Mother's Mercy\n";

    fout<<"6"<<", "<<"1"<<","<<"The Red Woman\n";
    fout<<"6"<<", "<<"2"<<","<<"Home\n";
    fout<<"6"<<", "<<"3"<<","<<"Oathbreaker\n";
    fout<<"6"<<", "<<"4"<<","<<"Book of the Stranger\n";
    fout<<"6"<<", "<<"5"<<","<<"The Door\n";
    fout<<"6"<<", "<<"6"<<","<<"Blood of My Blood\n";
    fout<<"6"<<", "<<"7"<<","<<"The Broken Man\n";
    fout<<"6"<<","<<"8"<<","<<"No One\n";
    fout<<"6"<<", "<<"9"<<","<<"Battle of the Bastards\n";
    fout<<"6"<<", "<<"10"<<","<<"The Winds of Winter\n";

    fout<<"7"<<", "<<"1"<<","<<"Dragonstone\n";
    fout<<"7"<<", "<<"2"<<","<<"Stormborn\n";
    fout<<"7"<<", "<<"3"<<","<<"The Queen's Justice\n";
    fout<<"7"<<", "<<"4"<<","<<"The Spoils of War\n";
    fout<<"7"<<", "<<"5"<<","<<"Eastwatch\n";
    fout<<"7"<<", "<<"6"<<","<<"Beyond the Wall\n";
    fout<<"7"<<", "<<"7"<<","<<"The Dragon and the Wolf\n";

    fout<<"8"<<", "<<"1"<<","<<"Winterfell\n";
    fout<<"8"<<", "<<"2"<<","<<"A Knight of the Seven Kingdoms\n";
    fout<<"8"<<", "<<"3"<<","<<"The Long Night\n";
    fout<<"8"<<", "<<"4"<<","<<"The Last of the Starks\n";
    fout<<"8"<<", "<<"5"<<","<<"The Bells\n";
    fout<<"8"<<", "<<"6"<<","<<"The Iron Throne\n";
    fout.close();
}
void read_episodes(Episodes m)
{
    fstream fin;
    fin.open("episode name.csv",ios::in);
    int c=0,r,l;
    vector<string>row;
    string line,word;
    while(getline(fin,line))
    {
        row.clear();
        stringstream s(line);
        while(getline(s,word,','))
        {
            row.push_back(word);
        }
        r=stoi(row[0]);
        l=stoi(row[1]);
        if(r==m.s && l==m.e)
        {
            c++;
            cout<<"Season "<<row[0]<<" and Episode "<<row[1]<<" title is: "<<row[2]<<"\n";
            if(m.s==1)
                cout<<"Episode Link:https://thepiratebay.org/torrent/14504230/Game_of_Thrones_Season_1_S01_720p_BluRay_x264"<<endl;
            if(m.s==2)
                cout<<"Episode Link:https://thepiratebay.org/torrent/11014810/Game_of_Thrones_-_Season_2_-_720p_BluRay_-_x264_-_ShAaNiG"<<endl;
            if(m.s==3)
                cout<<"Episode Link:https://thepiratebay.org/torrent/17908734/Game_of_Thrones_Season_3_Complete_1080p_x264_MKVTV"<<endl;
            if(m.s==4)
                cout<<"Episode Link:https://thepiratebay.org/torrent/11726921/Game_of_Thrones_-_Season_4_-_720p_BluRay_-_x264_-_ShAaNiG"<<endl;
            if(m.s==5)
                cout<<"Episode Link:https://thepiratebay.org/torrent/13711814/Game_of_Thrones_-_Season_5_-_720p_BluRay_-_x264_-_ShAaNiG"<<endl;
            if(m.s==6)
                cout<<"Episode Link:https://thepiratebay.org/torrent/15113168/Game_of_Thrones_-_Season_6_-_720p_HDTV_-_x265_HEVC_-_ShAaNiG"<<endl;
            if(m.s==7)
                cout<<"Episode Link:https://thepiratebay.org/torrent/18558065/Game.of.Thrones.S07.Season.7.Complete.720p.HDTV.X264-MRSK"<<endl;
            if(m.s==8)
                cout<<"Episode Link:https://thepiratebay.org/torrent/32848503/Game_Of_Thrones_S08_Complete_Season_8_720p_x264_AC3_5.1_[MKV]"<<endl;
            break;
        }
    }
    if(c!=1)
        cout<<"This episode doesn't exist"<<endl;
    fin.close();
}
void episode_delete()
{
    fstream fin,fout;
    fin.open("episode name.csv",ios::in);
    fout.open("episode list.csv",ios::out);
    int r,l,j,k,c=0;
    vector<string>row;
    string line,word;
    cout<<"Season:";
    cin>>j;
    cout<<"Episode:";
    cin>>k;
    while(!fin.eof())
    {
        row.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,','))
        {
            row.push_back(word);
        }
        int row_size=row.size();// ||
        r=stoi(row[0]);
        l=stoi(row[1]);
        if(r!=j || l!=k)
        {
            if(!fin.eof())
            {
                for(int i=0; i<row_size-1; i++)
                {
                    fout<<row[i]<<", ";
                }
                fout<<row[row_size-1]<<"\n";
            }
        }
        else
        {
            c=1;
        }
        if(fin.eof())
            break;
    }
    if(c==1)
        cout<<"Record deleted"<<"\n";
    else
        cout<<"Record not found"<<"\n";
    fin.close();
    fout.close();
    remove("episode name.csv");
    rename("episode list.csv","episode name.csv");
}
void watchlist()
{
    fstream fin,fout;
    fin.open("episode name.csv",ios::in);
    fout.open("episode watch.csv",ios::app);
    int r,l,j,k,c=0;
    vector<string>row;
    string line,word;
    cout<<"Season:";
    cin>>j;
    cout<<"Episode:";
    cin>>k;
    while(!fin.eof())
    {
        row.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,','))
        {
            row.push_back(word);
        }
        int row_size=row.size();// ||
        r=stoi(row[0]);
        l=stoi(row[1]);
        if(r==j && l==k)
        {
            c=0;
            if(!fin.eof())
            {
                for(int i=0; i<row_size-1; i++)
                {
                    fout<<row[i]<<", ";
                }
                fout<<row[row_size-1]<<"\n";
                cout<<"Added to Watchlist"<<"\n";
                break;
            }
        }
        else
            c=1;
    }
    if(c!=0)
    {
        cout<<"Record not found.Can't add to Watchlist.\n";
    }
    cout<<"\n";
    fin.close();
    fout.close();
}
int main()
{
    Episodes e;
    e.episode_name();
    character cha;
    cha.file_write();
    character ned("Eddard Stark",35),robb("Robb Stark",19),sansa("Sansa Stark",22),arya("Arya Stark",20),
              bran("Brandon Stark",19),aerys("King Aerys || Targaryen",39),rh("Rhaeger Targaryen",25),
              vis("Viserys Targaryen",22),dany("Daenerys Targaryen",23),jon("Jon Snow",23),jaime("Jaime Lannister",40),
              cer("Cersei Lannister",40),ty("Tyrion Lannister",39);
    House *s;
    for(int i=0;; i++)
    {
        cout<<"Enter as: "<<endl;
        cout<<"1.Editor.     2.User."<<endl;
        cout<<"Press 3 to Exit"<<endl;
        int l;
        cin>>l;
        if(l==3)
            break;
        else
        {
            switch(l)
            {
            case(1):
                if(logineditor())
                {
                    cout<<"Which property of Game of Thrones Do you want to know about?"<<endl;
                    cout<<"1.Characters    2.Episodes"<<endl;
                    int a,b,c,d,e,n,m;
                    cin>>a;
                    {
                        switch(a)
                        {
                        case(1):
                            cout<<"Which House do you want to know about?"<<endl;
                            cout<<"Press 1 for House Targaryen"<<endl;
                            cout<<"Press 2 for House Stark"<<endl;
                            cout<<"Press 3 for House Lannister"<<endl;
                            cin>>b;
                            switch(b)
                            {
                            case(1):
                                cout<<"Which Targaryn you want to know about?"<<endl;
                                cout<<"1.Aerys Targaryen"<<endl;
                                cout<<"2.Rhaegar Targaryen"<<endl;
                                cout<<"3.Viserys Targaryen"<<endl;
                                cout<<"4.Daenerys Targaryen"<<endl;
                                cout<<"5.Aegon Targaryen"<<endl;
                                cin>>c;
                                switch(c)
                                {
                                case(1):
                                    s=&aerys;
                                    cout<<aerys;
                                    cout<<"\n";
                                    s->read_record("aerys");
                                    cout<<"\n";
                                    s->targaryen();
                                    cout<<"\n";
                                    break;
                                case(2):
                                    s=&rh;
                                    cout<<rh;
                                    cout<<"\n";
                                    s->read_record("rhaegar");
                                    cout<<"\n";
                                    s->targaryen();
                                    cout<<"\n";
                                    break;
                                case(3):
                                    s=&vis;
                                    cout<<vis;
                                    cout<<"\n";
                                    s->read_record("viserys");
                                    cout<<"\n";
                                    s->targaryen();
                                    cout<<"\n";
                                    break;
                                case(4):
                                    s=&dany;
                                    cout<<dany;
                                    cout<<"\n";
                                    s->read_record("daenerys");
                                    cout<<"\n";
                                    s->targaryen();
                                    cout<<"\n";
                                    break;
                                case(5):
                                    s=&jon;
                                    cout<<jon;
                                    cout<<"\n";
                                    s->read_record("jon");
                                    cout<<"\n";
                                    s->targaryen();
                                    cout<<"\n";
                                    break;
                                default:
                                    cout<<"Record not found"<<endl;
                                    break;
                                }
                                break;
                            case(2):
                                cout<<"Which Stark you want to know about?"<<endl;
                                cout<<"1.Ned Stark "<<endl;
                                cout<<"2.Robb Stark"<<endl;
                                cout<<"3.Sansa Stark"<<endl;
                                cout<<"4.Arya Stark"<<endl;
                                cout<<"5.Brandon Stark"<<endl;
                                cin>>d;
                                switch(d)
                                {
                                case(1):
                                    s=&ned;
                                    cout<<ned;
                                    cout<<"\n";
                                    s->read_record("ned");
                                    cout<<"\n";
                                    s->stark();
                                    cout<<"\n";
                                    break;
                                case(2):
                                    s=&robb;
                                    cout<<robb;
                                    cout<<"\n";
                                    s->read_record("robb");
                                    cout<<"\n";
                                    s->stark();
                                    cout<<"\n";
                                    break;
                                case(3):
                                    s=&sansa;
                                    cout<<sansa;
                                    cout<<"\n";
                                    s->read_record("sansa");
                                    cout<<"\n";
                                    s->stark();
                                    cout<<"\n";
                                    break;
                                case(4):
                                    s=&arya;
                                    cout<<arya;
                                    cout<<"\n";
                                    s->read_record("arya");
                                    cout<<"\n";
                                    s->stark();
                                    cout<<"\n";
                                    break;
                                case(5):
                                    s=&bran;
                                    cout<<bran;
                                    cout<<"\n";
                                    s->read_record("bran");
                                    cout<<"\n";
                                    s->stark();
                                    cout<<"\n";
                                    break;
                                default:
                                    cout<<"Record not found"<<endl;
                                    break;
                                }
                                break;
                            case(3):
                                cout<<"Which Lannister you want to know about?"<<endl;
                                cout<<"1.Cersei Lannister"<<endl;
                                cout<<"2.Jaime Lannister"<<endl;
                                cout<<"3.Tyrion Lannister"<<endl;
                                cin>>e;
                                switch(e)
                                {
                                case(1):
                                    s=&cer;
                                    cout<<cer;
                                    cout<<"\n";
                                    s->read_record("cersei");
                                    cout<<"\n";
                                    s->Lannister();
                                    cout<<"\n";
                                    break;
                                case(2):
                                    s=&jaime;
                                    cout<<jaime;
                                    cout<<"\n";
                                    s->read_record("jaime");
                                    cout<<"\n";
                                    s->Lannister();
                                    cout<<"\n";
                                    break;
                                case(3):
                                    s=&ty;
                                    cout<<ty;
                                    cout<<"\n";
                                    s->read_record("tyrion");
                                    cout<<"\n";
                                    s->Lannister();
                                    cout<<"\n";
                                    break;
                                default:
                                    cout<<"Record not found"<<endl;
                                    break;
                                }
                                break;
                            default:
                                cout<<"Invalid Operation.Please start again\n"<<"\n";
                                break;
                            }
                            break;
                        case(2):
                            cout<<"1.Show Episode Record     2.Delete Episode Record"<<endl;
                            int f;
                            cin>>f;
                            switch(f)
                            {
                            case(1):
                                Episodes e1;
                                e1.getdata();
                                read_episodes(e1);
                                cout<<"\n";
                                break;
                            case(2):
                                episode_delete();
                                cout<<"\n";
                                break;
                            default:
                                cout<<"Invalid Operation.Please start again.\n";
                                cout<<"\n";
                            }
                            break;
                        default:
                            cout<<"Invalid Operation.Please start again.\n";
                            cout<<"\n";
                            break;
                        }
                        break;
                    }
                }
            case(2):
                User u;
                string g;
                cout<<"Register or Login?"<<endl;
                cin>>g;
                if(g=="login")
                    u.loginUser();
                else if(g=="register")
                    u.registerid();
                cout<<"\n";
                cout<<"Which property of Game of Thrones Do you want to know about?"<<endl;
                cout<<"1.Characters    2.Episodes"<<endl;
                int a,b,c,d,e,n,m;
                cin>>a;
                {
                    switch(a)
                    {
                    case(1):
                        cout<<"Which House do you want to know about?"<<endl;
                        cout<<"Press 1 for House Targaryen"<<endl;
                        cout<<"Press 2 for House Stark"<<endl;
                        cout<<"Press 3 for House Lannister"<<endl;
                        cin>>b;
                        switch(b)
                        {
                        case(1):
                            cout<<"Which Targaryn you want to know about?"<<endl;
                            cout<<"1.Aerys Targaryen"<<endl;
                            cout<<"2.Rhaegar Targaryen"<<endl;
                            cout<<"3.Viserys Targaryen"<<endl;
                            cout<<"4.Daenerys Targaryen"<<endl;
                            cout<<"5.Aegon Targaryen"<<endl;
                            cin>>c;
                            switch(c)
                            {
                            case(1):
                                s=&aerys;
                                cout<<aerys;
                                cout<<"\n";
                                s->read_record("aerys");
                                cout<<"\n";
                                s->targaryen();
                                cout<<"\n";
                                break;
                            case(2):
                                s=&rh;
                                cout<<rh;
                                cout<<"\n";
                                s->read_record("rhaegar");
                                cout<<"\n";
                                s->targaryen();
                                cout<<"\n";
                                break;
                            case(3):
                                s=&vis;
                                cout<<vis;
                                cout<<"\n";
                                s->read_record("viserys");
                                cout<<"\n";
                                s->targaryen();
                                cout<<"\n";
                                break;
                            case(4):
                                s=&dany;
                                cout<<dany;
                                cout<<"\n";
                                s->read_record("daenerys");
                                cout<<"\n";
                                s->targaryen();
                                cout<<"\n";
                                break;
                            case(5):
                                s=&jon;
                                cout<<jon;
                                cout<<"\n";
                                s->read_record("jon");
                                cout<<"\n";
                                s->targaryen();
                                cout<<"\n";
                                break;
                            default:
                                cout<<"Record not found"<<endl;
                                break;
                            }
                            break;
                        case(2):
                            cout<<"Which Stark you want to know about?"<<endl;
                            cout<<"1.Ned Stark "<<endl;
                            cout<<"2.Robb Stark"<<endl;
                            cout<<"3.Sansa Stark"<<endl;
                            cout<<"4.Arya Stark"<<endl;
                            cout<<"5.Brandon Stark"<<endl;
                            cin>>d;
                            switch(d)
                            {
                            case(1):
                                s=&ned;
                                cout<<ned;
                                cout<<"\n";
                                s->read_record("ned");
                                cout<<"\n";
                                s->stark();
                                cout<<"\n";
                                break;
                            case(2):
                                s=&robb;
                                cout<<robb;
                                cout<<"\n";
                                s->read_record("robb");
                                cout<<"\n";
                                s->stark();
                                cout<<"\n";
                                break;
                            case(3):
                                s=&sansa;
                                cout<<sansa;
                                cout<<"\n";
                                s->read_record("sansa");
                                cout<<"\n";
                                s->stark();
                                cout<<"\n";
                                break;
                            case(4):
                                s=&arya;
                                cout<<arya;
                                cout<<"\n";
                                s->read_record("arya");
                                cout<<"\n";
                                s->stark();
                                cout<<"\n";
                                break;
                            case(5):
                                s=&bran;
                                cout<<bran;
                                cout<<"\n";
                                s->read_record("bran");
                                cout<<"\n";
                                s->stark();
                                cout<<"\n";
                                break;
                            default:
                                cout<<"Record not found"<<endl;
                                break;
                            }
                            break;
                        case(3):
                            cout<<"Which Lannister you want to know about?"<<endl;
                            cout<<"1.Cersei Lannister"<<endl;
                            cout<<"2.Jaime Lannister"<<endl;
                            cout<<"3.Tyrion Lannister"<<endl;
                            cin>>e;
                            switch(e)
                            {
                            case(1):
                                s=&cer;
                                cout<<cer;
                                cout<<"\n";
                                s->read_record("cersei");
                                cout<<"\n";
                                s->Lannister();
                                cout<<"\n";
                                break;
                            case(2):
                                s=&jaime;
                                cout<<jaime;
                                cout<<"\n";
                                s->read_record("jaime");
                                cout<<"\n";
                                s->Lannister();
                                cout<<"\n";
                                break;
                            case(3):
                                s=&ty;
                                cout<<ty;
                                cout<<"\n";
                                s->read_record("tyrion");
                                cout<<"\n";
                                s->Lannister();
                                cout<<"\n";
                                break;
                            default:
                                cout<<"Record not found"<<endl;
                                break;
                            }
                            break;
                        default:
                            cout<<"Invalid Operation.Please start again\n"<<"\n";
                            break;
                        }
                        break;
                    case(2):
                        cout<<"1.Show Episode Record     2.Add Episode to watchlist"<<endl;
                        int f;
                        cin>>f;
                        switch(f)
                        {
                        case(1):
                            Episodes e1;
                            e1.getdata();
                            read_episodes(e1);
                            cout<<"\n";
                            break;
                        case(2):
                            watchlist();
                            break;
                        default:
                            cout<<"Invalid Operation.Please start again.\n";
                        }
                        break;
                    default:
                        cout<<"Invalid Operation.Please start again.\n"<<"\n";
                        break;
                    }
                    break;
                }
            }
        }
    }
}



