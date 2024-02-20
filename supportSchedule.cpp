#include<bits/stdc++.h>
using namespace std;
typedef         long long       ll;
typedef         vector<ll>      vll;
#define         ss              ' '
#define         nn              "\n"
#define         fi              first
#define         se              second
#define         PB              pop_back
#define         pb              push_back
#define         pi              acos(-1.0)
#define         gcd(a,b)        __gcd(a,b)
#define         OO              1000000007
#define         NN              printf("\n")
#define         zz(v)           (ll)v.size()
#define         lcm(a,b)        (a*b)/gcd(a,b)
#define         no              printf("NO\n")
#define         mo              printf("-1\n")
#define         yes             printf("YES\n")
#define         S(a)            scanf("%lld",&a)
#define         all(p)          p.begin(),p.end()
#define         P(a)            printf("%lld\n",a)
#define         db              printf("be steady\n")
#define         mms(ar,a)       memset(ar,a,sizeof(ar))
#define         SS(a,b)         scanf("%lld %lld",&a,&b)
#define         PP(a,b)         printf("%lld %lld\n",a,b)
#define         prv(v)          for(auto it:v) cout<<it<<ss;NN;
#define         prvs(v)         for(auto it:v) cout<<it<<nn;NN;
#define         SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)

ll ar[300010],memNum=9;
vll v;
vector<string>pairs,weekend,calendar;
map<string,ll>mp;
map<char,string>chrName;
map<string,char>nameChar;
map<char,ll>inMonthCnt;

void nameinit(){
    chrName['a']="sakib";
    chrName['b']="ruman";
    chrName['c']="yamin";
    chrName['d']="rakib";
    chrName['e']="safayat";
    chrName['f']="fahim";
    chrName['g']="nouros";
    chrName['h']="misbah";
    chrName['i']="porosh";

    nameChar["sakib"]='a';
    nameChar["ruman"]='b';
    nameChar["yamin"]='c';
    nameChar["rakib"]='d';
    nameChar["safayat"]='e';
    nameChar["fahim"]='f';
    nameChar["nouros"]='g';
    nameChar["misbah"]='h';
    nameChar["porosh"]='i';
}

vector<string> generateCalendar(int year) {
    vector<string> calendarRows;

    for (int month = 1; month <= 12; ++month) {
        tm timeinfo = {0, 0, 0, 1, month - 1, year - 1900};
        mktime(&timeinfo);

        int daysInMonth = 31; // a rough estimate
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysInMonth = 30;
        } else if (month == 2) {
            daysInMonth = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
        }

        for (int day = 1; day <= daysInMonth; ++day) {
            timeinfo.tm_mday = day;
            mktime(&timeinfo);

            // Check if it's not Saturday (6) or Sunday (0)
            if (timeinfo.tm_wday != 0 && timeinfo.tm_wday != 6) {
                ostringstream row;
                row << setw(10) << put_time(&timeinfo, "%d-")
                    << setw(15) << put_time(&timeinfo, "%B-")
                    << setw(15) << put_time(&timeinfo, "%A");

                calendarRows.push_back(row.str());
            }
        }
    }

    return calendarRows;
}

void remove_weekend(){
    cout<<"enter a date to remove in <date month> formate, ex: 01-feb -> ";
    string dt;
    cin>>dt;
    weekend.pb(dt);
    ll p=0;
    string stt="";
    for(ll j=0;j<zz(weekend);j++){
        dt=weekend[j];
        for(ll i=0;i<zz(calendar);i++){
            string st=calendar[i];
            string st2=st.substr(0, 6);
            if(st2==dt){
                calendar.erase(calendar.begin()+i);
                stt=st2;
                p=1;
                break;
            }
        }
    }

    if(!p){
        cout<<"invalid date or the date is not in calender list----------"<<nn<<nn;
    }
    else{
        cout<<stt<<" - removed from calender list---------"<<nn<<nn;
    }
    cout<<nn<<"---------------------"<<nn;
    NN;
}

void days_for_one(){
    string name;
    cout<<"enter a name to see all days assigned -> ";
    cin>>name;
    char ch=nameChar[name];
    for(ll i=0;i<zz(pairs);i++){
        if(ch==pairs[i][0] or ch==pairs[i][1]){
            cout<<setw(22)<<left<<calendar[i*2]<<" <-->   "<<setw(8)<<left<<chrName[pairs[i][0]]<<" -   "<<setw(8)<<chrName[pairs[i][1]]<<nn;
            if(calendar[i*2].substr(0, 6)!="31-dec")
                cout<<setw(22)<<left<<calendar[i*2+1]<<" <-->   "<<setw(8)<<left<<chrName[pairs[i][0]]<<" -   "<<setw(8)<<chrName[pairs[i][1]]<<nn;
        }
    }
    cout<<nn<<"---------------------"<<nn;
    NN;
}

void print_days(){
    for(ll i=0;i<zz(calendar)/2;i++){
        cout<<setw(22)<<left<<calendar[i*2]<<" <-->   "<<setw(8)<<left<<chrName[pairs[i][0]]<<" -   "<<setw(8)<<chrName[pairs[i][1]]<<nn;
        if(calendar[i*2].substr(0, 6)!="31-dec")
            cout<<setw(22)<<left<<calendar[i*2+1]<<" <-->   "<<setw(8)<<left<<chrName[pairs[i][0]]<<" -   "<<setw(8)<<chrName[pairs[i][1]]<<nn;
    }
    cout<<nn<<"---------------------"<<nn;
    NN;
}

void change_place(){
    cout<<"enter member's name to change schedule -> ";
    string name,dt;
    cin>>name;
    cout<<"enter members date in <date month> formate, ex: 01-feb -> ";
    cin>>dt;
    ll id=-1;
    for(ll i=0;i<zz(calendar);i++){
        string st=calendar[i];
        string st2=st.substr(0, 6);
        if(st2==dt){
            id=i;
            break;
        }
    }
    id/=2;
    cout<<pairs[id][0]<<ss<<pairs[id][1]<<nn;
    char ch=nameChar[name];
    if(id>=0){
        if(pairs[id][0]==ch){
            swap(pairs[id][0],pairs[id+1][0]);
            cout<<"swapped "<<chrName[pairs[id][0]]<<" with "<<chrName[pairs[id+1][0]]<<nn;
        }
        else if(pairs[id][1]==ch){
            swap(pairs[id][1],pairs[id+1][1]);
            cout<<"swapped "<<chrName[pairs[id][1]]<<" with "<<chrName[pairs[id+1][1]]<<nn;
        }
        else cout<<"not found"<<nn;
    }
    cout<<nn<<"----------------------"<<nn;
    NN;
}

void current_count(){
    string month;
    cout<<"enter the month -> ";
    cin>>month;
    NN;
    for(ll i=0;i<zz(pairs);i++){
        ll id1=i*2;
        ll id2=i*2+1;
        if(id1<zz(calendar)){
            string st1=calendar[id1];
            string st2=st1.substr(3, 3);
            if(st2==month){
                inMonthCnt[pairs[i][0]]++;
                inMonthCnt[pairs[i][1]]++;
            }
        }
        if(id2<zz(calendar)){
            string st1=calendar[id2];
            string st2=st1.substr(3, 3);
            if(st2==month){
                inMonthCnt[pairs[i][0]]++;
                inMonthCnt[pairs[i][1]]++;
            }
        }
    }
    for(auto it : inMonthCnt){
        cout<<chrName[it.fi]<<" --> "<<it.se<<nn;
    }
    inMonthCnt.clear();
    cout<<nn<<"----------------------"<<nn;
    NN;
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output1.txt", "w", stdout);
    ll t,i,a=1,id=0,j,k,cnt=0;
    string pt="ab cd ef gh ia bc de fg hi ac bd eg fh ib ce df ga hb ic ae dg fa gb hc id eb fc gd ha ie ad bf cg he if ag bh ";
    nameinit();
    int year = 2024;
    calendar = generateCalendar(year);
    for(i=0;i<zz(calendar);i++){
        for(j=0;j<zz(calendar[i]);j++){
            if(isupper(calendar[i][j])) calendar[i][j]=tolower(calendar[i][j]);
        }
    }
    while(calendar[0]!="01-february-thursday") calendar.erase(calendar.begin());
//    while(calendar[0]!="01 March Friday") calendar.erase(calendar.begin());
    for(i=0;i<zz(pt)-1;i++){
        if(pt[i]!=' ' and pt[i+1]!=' '){
            string st="";
            st+=pt[i];
            st+=pt[i+1];
            pairs.pb(st);
        }
    }
    for(i=0;zz(pairs)<zz(calendar)/2+1;i++){
        pairs.pb(pairs[i]);
    }

    ll tt=111;
    while(tt--){
        ll var;
        var=111;
        cout<<"1 - remove a weekend"<<nn;
        cout<<"2 - watch days for a member"<<nn;
        cout<<"3 - change a members place"<<nn;
        cout<<"4 - count in current month"<<nn;
        cout<<"5 - check all days"<<nn;
        cout<<"enter your choice-> ";
        cin>>var;
        if(var==1){
            remove_weekend();
        }
        if(var==2){
            days_for_one();
        }
        if(var==3){
            change_place();
        }
        if(var==4){
            current_count();
        }
        if(var==5){
            print_days();
        }
    }

    return 0;
}
