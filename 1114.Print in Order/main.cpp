/*Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

 

Example 1:

Input: [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
Example 2:

Input: [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/print-in-order
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Foo {
public:
    Foo() {
        mtx2.lock();
        mtx3.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        mtx2.unlock();
    }

    void second(function<void()> printSecond) {
        mtx2.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        mtx3.unlock();
    }

    void third(function<void()> printThird) {
        mtx3.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        mtx3.unlock();
    }
    mutex mtx2,mtx3;
};
