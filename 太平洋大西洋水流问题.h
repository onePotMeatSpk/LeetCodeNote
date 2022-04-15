#pragma once
#include<vector>
using namespace std;
//��Ŀ��̫ƽ�������ˮ������
//��Ŀ����������һ����ά�ķǸ���������ÿ��λ�õ�ֵ��ʾ���θ߶ȡ�������ߺ��ϱ���̫ƽ���ұߺ��±��Ǵ�����
//			�����Щλ��������ˮ�����Լ�������̫ƽ����������������ˮֻ�ܴӺ��θߵ�λ���������εͻ���ͬ��λ�á�

//�㷨˼�룺����½ĳ�������ͨ�������ܵ���С�ڵ��ڵ�ǰ��ĵ���б����Ļ������ж�ĳ���Ƿ����ͬʱ���������ϻ���鷳
//����Ӻ��ߵĵ���б��������ߵĵ��ǿ϶����Ե�������ڵĴ���ģ����Ҵ��ڵ��ڵ�ǰ��ĵ㣬��˵���Ǹ���϶����Ծ��ɵ�ǰ�㵽��ô���
//����������ֿ������ۣ��õ����Ե���ĳ������ĵ�ľ��������ĳ�������������϶���1��˵���õ����ͬʱ������������



//�ݹ麯��
void pacificAtlanticCore(vector<vector<int>>& heights, vector<vector<bool>>& valley, const int& m, const int& n, int y, int x)
{
    if (valley[y][x])    return;//����õ��Ѿ�ȷ�����������󺣣��Ͳ��ٹܸõ�
    valley[y][x] = 1;//�Ѿ��������˸õ㣬��˵���õ���������������
    //������ܵ��е�ĳ���ĺ��θ��ڵ�ǰ�㣬�����϶�����������ǰ�㣬����ǰ��϶����������󺣣���ô�Ǹ���Ҳ�϶����������󺣣����Ա����Ǹ������ҵ�����ĵ�
    //ע��߽���ƣ���ֹ��������Խ��
    if (y - 1 >= 0 && heights[y - 1][x] >= heights[y][x])  pacificAtlanticCore(heights, valley, m, n, y - 1, x);
    if (y + 1 < m && heights[y + 1][x] >= heights[y][x])  pacificAtlanticCore(heights, valley, m, n, y + 1, x);
    if (x - 1 >= 0 && heights[y][x - 1] >= heights[y][x])  pacificAtlanticCore(heights, valley, m, n, y, x - 1);
    if (x + 1 < n && heights[y][x + 1] >= heights[y][x])  pacificAtlanticCore(heights, valley, m, n, y, x + 1);
}

//������
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> valleyPacific(m, vector<bool>(n, 0));//�ɵ���̫ƽ��ĵ�
    vector<vector<bool>> valleyAtlantic(m, vector<bool>(n, 0));//�ɵ��������ĵ�
    vector<vector<int>> route;//��ͬʱ��������ĵ�

    //����̫ƽ�󣬴ӽ���̫ƽ��ĺ�����ʼ����
    for (int i = 0; i < m; i++)  pacificAtlanticCore(heights, valleyPacific, m, n, i, 0);
    for (int i = 0; i < n; i++)  pacificAtlanticCore(heights, valleyPacific, m, n, 0, i);
    //��������󣬴ӽ��ڴ�����ĺ�����ʼ����
    for (int i = 0; i < m; i++)  pacificAtlanticCore(heights, valleyAtlantic, m, n, i, n - 1);
    for (int i = 0; i < n; i++)  pacificAtlanticCore(heights, valleyAtlantic, m, n, m - 1, i);

    //��ȡ��ͬʱ���Ե�������ĵ�
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (valleyPacific[i][j] && valleyAtlantic[i][j]) route.push_back(vector<int>{i, j});

    return route;
}