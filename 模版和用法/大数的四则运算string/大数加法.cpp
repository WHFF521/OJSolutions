#include<string>
using namespace std;

bool CheckZero(const string &str){      //检查是否等于0
    int size=str.size();                //如果全是0则为0，这里假设不会有带符号的+00000或者-00000作为输入
    for(int i=0;i<size;i++)
        if(str[i]!='0') return false;
    return true;
}

string Add(string str1, string str2){
    //关于0的处理
    if(CheckZero(str1)&&CheckZero(str2)) return "0";    //如果都是0
    else if(CheckZero(str1)) return str2;               //如果有个一为0
    else if(CheckZero(str2)) return str1;
    string ans;
    int i=str1.size()-1,j=str2.size()-1;
    int flag=0;                                         //进位标记
    while(i>=0||j>=0||flag){
        int numa=i>=0?str1[i--]-'0':0;                  //如果所有位都访问完毕，对应的位置用0代替
        int numb=j>=0?str2[j--]-'0':0;
        flag=numa+numb+flag;                            //计算两位的和
        ans+='0'+flag%10;                               //取个位保存在答案中
        flag/=10;                                       //计算进位
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
