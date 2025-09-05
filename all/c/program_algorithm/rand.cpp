#include<iostream>
#include<random>
#include<type_traits>
#include <chrono>
#include<unordered_map>
#include <functional> 
#include<map>
#include<string>
#include<vector>
#include <memory>
#include <cassert>
#include<algorithm>
using namespace std;
std::mt19937_64 engine(std::chrono::steady_clock::now().time_since_epoch().count());
template<class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
T rand(T l, T r) { return std::uniform_int_distribution<T>(l, r)(engine); }
//有一个数组，随机打乱它，要求最后每一种排列出现的可能性相等，
/*
const int maxn = 1e1 + 5;
int arr[maxn];
void shuffle(int len)
{
	if (len == 1)return;
	swap(arr[len - 1], arr[rand(0, len - 1)]);
	shuffle(len - 1);
}
int main()
{
	for (int i = 0; i < maxn; i++)arr[i] = i + 1;
	shuffle(maxn);
	for (int i = 0; i < maxn; ++i)
		cout << arr[i] << ' ';cout << endl;
}
*/

//你现在要从 [1,n] 中均匀随机选出 m 个 不重复 的数，其中 1≤n≤10^18，
/*
typedef unsigned long long ull;
inline vector<ull>select(ull n, int m)
{
	unordered_map<ull, ull>rest;
	vector<ull>tmp(m);
	for (ull i = 0; i < m; i++)tmp[i] = i + 1;
	for (ull i = 0; i < m; i++)
	{
		const ull j = rand<ull>(i, n - 1);
		if (j < m)swap(tmp[i], tmp[j]);
		else if (rest.find(j) == rest.end())
		{
			rest[j] = tmp[i]; tmp[i] = j + 1;
		}
		else { swap(tmp[i], rest[j]); }
	}
	return tmp;
}
int main()
{
	vector<ull>ans=select(10000000000000, 10);
	for (ull j : ans)cout << j << " "; cout << endl;
}
*/


//括号序列:空串是合法的括号序列,如果 A 是合法的括号序列，那么 (A) 和 A() 也是合法的括号序列
/*
inline string brackets(size_t n) {
	const size_t len = n << 1;
	vector<bool>arr(len);
	fill(arr.begin(), arr.begin()+n, 1);
	fill(arr.begin() + n, arr.begin() + len, 0);
	shuffle(arr.begin(), arr.begin() + len, engine);
	size_t start = 0, end = len;
	while (1)
	{
		size_t lef_count = 0, rig_count = 0;
		bool ok = 1;
		for (size_t i = start, j; i < end; ++i)
		{
			++(arr[i] ? rig_count : lef_count);
			if (lef_count >= rig_count) continue;
			for (j = i + 1; j < end; ++j) {
				++(arr[j] ? rig_count : lef_count);
				if (rig_count > lef_count) continue;
				const size_t len = j - i - 1;
				rotate(arr.begin() + i + 1, arr.begin() + j + 1, arr.begin() + end);
				copy_backward(arr.begin() + end - len - 1, arr.begin() + end - 1, arr.begin() + end);
				transform(arr.begin() + end - len, arr.begin() + end, arr.begin() + end - len, std::logical_not<bool>());
				arr[i] = 0; arr[end - len - 1] = 1;
				start = i + 1; end = end - len - 1;
				ok = false;
				break;
			}
		}
		if (ok) break;
	}
	std::string ret; ret.resize(len);
	for (size_t i = 0; i < len; ++i) ret[i] = "()"[arr[i]];
	return ret;
}
//int main()
//{
//	string s = brackets(10);
//	cout << s << endl;
//}


//生成有根二叉树
template<class T>
using Ptr = typename std::unique_ptr<T>;
struct node
{
	Ptr<node> lson, rson;
	node(Ptr<node> lson, Ptr<node> rson) :lson(std::move(lson)), rson(std::move(rson)) {}
};

inline std::string brackets(const Ptr<node>& tr) {
	if (!tr) return "";
	std::string ret;
	ret += '(';
	ret += brackets(tr->lson);
	ret += ')';
	ret += brackets(tr->rson);
	return ret;
}
inline Ptr<node> binary_tree(const std::string& str) {
	if (str.empty()) return nullptr;
	int i = 0, sum = 0;
	do sum += str[i++] == '(' ? 1 : -1; while (sum);
	auto lstr = str.substr(1, i - 2), rstr = str.substr(i);
	return std::make_unique<node>(binary_tree(lstr), binary_tree(rstr));
}
inline Ptr<node> binary_tree(size_t n) { return binary_tree(brackets(n)); }
int assign_ids(const Ptr<node>& root, unordered_map<const node*, int>& id_map, int& counter) {
	if (!root) return 0;
	int my_id = ++counter;
	id_map[root.get()] = my_id;
	assign_ids(root->lson, id_map, counter);
	assign_ids(root->rson, id_map, counter);
	return my_id;
}

// 打印树结构
void print_tree(const Ptr<node>& root, unordered_map<const node*, int>& id_map) {
	if (!root) return;
	int my_id = id_map[root.get()];
	if (root->lson) {
		int left_id = id_map[root->lson.get()];
		cout << my_id << " -> " << left_id << " (L)" << endl;
		print_tree(root->lson, id_map);
	}
	if (root->rson) {
		int right_id = id_map[root->rson.get()];
		cout << my_id << " -> " << right_id << " (R)" << endl;
		print_tree(root->rson, id_map);
	}
}
int main() {
	Ptr<node> root = binary_tree(5);
	unordered_map<const node*, int> id_map;
	int counter = 0;
	assign_ids(root, id_map, counter);
	cout << "Tree edges:" << endl;
	print_tree(root, id_map);
}
*/

//构造tree
/*
inline std::vector<std::pair<int, int>> tree(int n) {
	assert(n > 0); std::vector<std::pair<int, int>> ret;
	if (n == 1) return ret;
	std::vector<int> prufer; prufer.resize(n - 2);
	for (int& v : prufer) v = rand(1, n);

	vector<int>deg(n + 1);
	std::fill(deg.begin() + 1, deg.begin() + n + 1, 1);
	for (int x : prufer) ++deg[x];
	int ptr = 0; while (deg[++ptr] != 1);
	int leaf = ptr;
	for (int x : prufer) {
		ret.emplace_back(x, leaf);
		if (--deg[x] == 1 && x < ptr) leaf = x;
		else {
			while (deg[++ptr] != 1);
			leaf = ptr;
		}
	}
	ret.emplace_back(leaf, n);
	return ret;
}

int main()
{
	auto tr = tree(5);
	for (auto it : tr)
		std::cout << it.first << ' ' << it.second << std::endl;
	//pov:
	//实际造数据，大部分会
	int n;
	for (int i = 2; i <= n; ++i)
		std::cout << rand(1, i) << ' ' << i << std::endl;
}
*/