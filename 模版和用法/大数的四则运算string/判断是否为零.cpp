// # 商业转载请联系作者获得授权，非商业转载请注明出处。
// # For commercial use, please contact the author for authorization. For non-commercial use, please indicate the source.
// # 协议(License)：署名-非商业性使用-相同方式共享 4.0 国际 (CC BY-NC-SA 4.0)
// # 作者(Author)：songjiahao
// # 链接(URL)：https://blog.songjiahao.com/archives/382
// # 来源(Source)：SAquariusの梦想屋
#include<string>
using namespace std;

bool CheckZero(const string &str){      //检查是否等于0
    int size=str.size();                //如果全是0则为0，这里假设不会有带符号的+00000或者-00000作为输入
    for(int i=0;i<size;i++)
        if(str[i]!='0') return false;
    return true;
}
