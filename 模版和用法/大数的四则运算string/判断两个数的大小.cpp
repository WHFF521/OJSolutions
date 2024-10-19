// # 商业转载请联系作者获得授权，非商业转载请注明出处。
// # For commercial use, please contact the author for authorization. For non-commercial use, please indicate the source.
// # 协议(License)：署名-非商业性使用-相同方式共享 4.0 国际 (CC BY-NC-SA 4.0)
// # 作者(Author)：songjiahao
// # 链接(URL)：https://blog.songjiahao.com/archives/382
// # 来源(Source)：SAquariusの梦想屋
#include<string>
using namespace std;
bool Lower(string str1, string str2){                   //长度长的一定大（这里假设除了0以外，都没有前导0），长度相等则字典序小的数字更小
    return str1.size()<str2.size()||(str1.size()==str2.size()&&str1<str2);
}
