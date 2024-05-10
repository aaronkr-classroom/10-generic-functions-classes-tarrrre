// split.h
#ifndef GUARD_split_h
#define GUARD_split_h

#include <algorithm> // find_if()
#include <cctype> // isspace()
#include <string>

using namespace std;

// �μ��� ������ ���� true, �׷��� ���� ���� false
inline bool space(char c) {
	return isspace(c);
}

// �μ��� ������ ���� false, �׷��� ���� ���� true
inline bool not_space(char c) {
	return !isspace(c);
}
template <class Out>
void split(const string& str, Out os) {
	typedef string::const_iterator iter;
	iter i = str.begin();
	

	// for(iter != str.begin(); i != str.end(); i++)
	while (i != str.end()) {


		// ���� ������ ���� 
		// ���� i��ġ���� ù ��° �پ�� �ƴ� ���� ã��
		i = find_if(i, str.end(), not_space);


		// ���� �ܾ��� ���� ã��
		// while �ݺ��� �� �׻� ���ο� �ݺ��� j�� ���� 
		// ���� i��ġ���� ù ��° �پ�� ���� ã��
		iter j = find_if(i, str.end(), space);


		// [i,j)  ������ ���ڸ� ���� 
		if (i != str.end()) {
			*os++ = string(i, j);
		}

		// i�ݺ��� ��ġ�� j�ݺ����� ��ġ�� �����ϱ�
		i = j;


	}
	

}




#endif