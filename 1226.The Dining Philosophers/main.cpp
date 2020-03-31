/*Five silent philosophers sit at a round table with bowls of spaghetti. Forks are placed between each pair of adjacent philosophers.

Each philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left and right forks. Each fork can be held by only one philosopher and so a philosopher can use the fork only if it is not being used by another philosopher. After an individual philosopher finishes eating, they need to put down both forks so that the forks become available to others. A philosopher can take the fork on their right or the one on their left as they become available, but cannot start eating before getting both forks.

Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand are assumed.

Design a discipline of behaviour (a concurrent algorithm) such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-dining-philosophers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class DiningPhilosophers {
private:
    mutex lock[5];
public:
    DiningPhilosophers() {

    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher+1)%5;
        if((l&1)==1){
            lock[l].lock();
            lock[r].lock();
        }else{
            lock[r].lock();
            lock[l].lock();
        }

        pickLeftFork();
        pickRightFork();
        eat();
        putRightFork();
        putLeftFork();
        lock[l].unlock();
        lock[r].unlock();
    }
};