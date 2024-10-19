`iomanip` 库中的方法主要用于控制 `cout` 的输出格式，常用于控制数值、字符串的对齐、精度、小数点等格式。下面是一些常用的方法及其示例：

### 1. `setw(int n)`：设置输出宽度
设定输出字段的宽度，宽度不足时会在左边填充空格，常和 `setfill` 搭配使用。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setw(10) << 123 << endl;  // 输出宽度为10，右对齐
    return 0;
}
```

**输出**：
```
       123
```

### 2. `setfill(char c)`：设置填充字符
用于指定 `setw` 不足时的填充字符。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setfill('*') << setw(10) << 123 << endl;  // 用'*'填充
    return 0;
}
```

**输出**：
```
*******123
```

### 3. `setprecision(int n)`：设置浮点数的精度
设置浮点数的有效数字或小数点后保留的位数，结合 `fixed` 或 `scientific` 使用。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setprecision(3) << 123.45678 << endl; // 保留3位有效数字
    cout << fixed << setprecision(3) << 123.45678 << endl; // 固定小数点后3位
    return 0;
}
```

**输出**：
```
123
123.457
```

### 4. `fixed` 和 `scientific`：控制浮点数格式
- `fixed`：以固定的小数点格式显示浮点数。
- `scientific`：以科学计数法显示浮点数。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << fixed << setprecision(2) << 123.456 << endl;  // 输出固定格式
    cout << scientific << setprecision(2) << 123.456 << endl;  // 输出科学计数法
    return 0;
}
```

**输出**：
```
123.46
1.23e+02
```

### 5. `left` 和 `right`：控制对齐方式
`left` 设置左对齐，`right` 设置右对齐，常与 `setw` 搭配使用。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << left << setw(10) << 123 << right << setw(10) << 456 << endl;
    return 0;
}
```

**输出**：
```
123       456
```

### 6. `showpoint`：强制显示小数点
即使浮点数为整数，也显示小数点。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << showpoint << 123.0 << endl;  // 输出小数点
    return 0;
}
```

**输出**：
```
123.000
```

### 7. `hex`，`oct`，`dec`：设置整数的进制
用于将整数输出为十六进制、八进制或十进制格式。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << hex << 255 << endl;  // 输出十六进制
    cout << oct << 255 << endl;  // 输出八进制
    cout << dec << 255 << endl;  // 输出十进制
    return 0;
}
```

**输出**：
```
ff
377
255
```