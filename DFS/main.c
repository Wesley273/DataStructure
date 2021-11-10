#include <stdio.h>
const int true=1;
const int false=0;
char maze[8][8];                          //保存地图信息
int n, m, t;                              //地图大小为n*m,从起点到终点能否恰好t秒
int success;                             //是否找到所需状态标记
int go[][2] = {1, 0, -1, 0, 0, 1, 0, -1}; //四方向行走坐标差
void DFS(int x, int y, int time)
{ //递归形式的深度优先搜索
    for (int i = 0; i < 4; i++)
    { //枚举四个相邻位置
        int nx = x + go[i][0];
        int ny = y + go[i][1]; //计算其坐标
        if (nx < 1 || nx > n || ny < 1 || ny > m)
            continue; //若坐标在地图外则跳过
        if (maze[nx][ny] == 'X')
            continue; //若该位置为墙,跳过
        if (maze[nx][ny] == 'D')
        { //若该位置为门
            if (time + 1 == t)
            {                   //若所用时间恰好为t
                success = true; //搜索成功
                return;         //返回
            }
            else
                continue; //否则该状态的后续状态不可能为答案(经过的点不能再经过),跳过
        }
        maze[nx][ny] = 'X';    //该状态扩展而来的后续状态中,该位置都不能被经过,直接修改该位置为墙
        DFS(nx, ny, time + 1); //递归扩展该状态,所用时间递增
        maze[nx][ny] = '.';    //若其后续状态全部遍历完毕,则退回上层状态,将因为要搜索其后续状态而改成墙的位置,改回普通位置
        if (success)
            return; //假如已经成功,则直接返回,停止搜索
    }
}
int main()
{
    while (scanf("%d%d%d", &n, &m, &t) != EOF)
    {
        if (n == 0 && m == 0 && t == 0)
            break;
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", maze[i] + 1);
        }                //输入
        success = false; //初始化成功标记
        int sx, sy;
        for (int i = 1; i <= n; i++)
        { //寻找D的位置坐标
            for (int j = 1; j <= m; j++)
            {
                if (maze[i][j] == 'D')
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        { //寻找初始状态
            for (int j = 1; j <= m; j++)
            {
                if (maze[i][j] == 'S' && (i + j) % 2 == ((sx + sy) % 2 + t % 2) % 2)
                {                     //找到S点后,先判断S与D的奇偶性关系,是否和t符合,即符合上式,若不符合直接跳过搜索
                    maze[i][j] = 'X'; //将起点标记为墙
                    DFS(i, j, 0);     //递归扩展初始状态
                }
            }
        }
        puts(success == true ? "YES" : "NO"); //若success为真,则输出yes
    }
    return 0;
}