
#include <fstream>
#include <iostream>

using namespace std;

class wiki {

public:
	int number;
	int connect;
	int *from;
	int *in;

	//
	int *step;
	int *way;
	string P = "Python";
	string S = "Список_файловых_систем";
	int Pnum = 0;
	int Snum = 0;
	wiki() {
		ifstream t;
		t.open("C:/Users/Admin/Documents/test/wiki/wiki/file.txt");
		if (!t.is_open())
		{
			cerr << "error" << endl;
			t.clear();
		}
		t >> number >> connect;
		from = new int[number];
		in = new int[connect];
		step = new int[number];
		for (int j = 0; j<number; j++) {
			step[j] = 0;
		}
		int * l = in;
		for (int j = 0; j<number; j++) {
			int n;

			string step_up;
			t >> step_up;
			if (step_up == P) Pnum = j;
			if (step_up == S) Snum = j;
			t >> n;
			t >> n;
			if (n) {
				step[j] = 1;
			}
			t >> n;
			from[j] = n;
			for (int k = 0; k<n; k++) {
				t >> *l;
				l++;
			}
		}
		t.close();
		for (int j = 1; j<number; j++) {
			from[j] += from[j - 1];
		}
		*(from - 1) = 0;
		way = new int;
	}

	~wiki() {
		delete[] from;
		delete[] in;
		delete[] way;
	}



	void q1() {

		int sum;
		for (int j = 0; j<number; j++) {
			sum += step[j];
		}
		cout << " " << sum << endl;
	}

	void min_from() {
		int sum = 1;
		int val = from[0];
		for (int j = 1; j<number; j++) {
			if (val>from[j] - from[j - 1]) {
				val = from[j] - from[j - 1];
				sum = 0;
			}
			if (val == from[j] - from[j - 1]) {
				sum++;
			}
		}
		cout << "" << val << "" << sum << endl;
	}

	void max_from() {
		int sum = 1;
		int val = from[0];
		for (int j = 1; j<number; j++) {
			if (val<from[j] - from[j - 1]) {
				val = from[j] - from[j - 1];
				sum = 0;
			}
			if (val == from[j] - from[j - 1]) {
				sum++;
			}
		}
		int num_max = 0;
		for (int j = 1; j<number; j++) {
			if (from[j] - from[j - 1] == val) num_max = j;
		}
		cout << "max num  " << val << "  " << sum << endl << " " << num_max << endl;;
	}

	void av_from() {
		cout << "aver num " << (double)connect / number << endl;
	}

	void min_in() {
		int* num;
		num = new int[number];
		for (int j = 0; j<number; j++) {
			num[j] = 0;
		}

		for (int j = 0; j<connect; j++) {
			num[in[j]]++;
		}
		if (step[0]) {
			num[in[from[0]]]--;
		}
		for (int j = 1; j<number; j++) {
			if (step[j]) {
				num[in[from[j - 1]]]--;
			}
		}

		int sum = 0;
		int val = num[0];
		for (int j = 0; j<number; j++) {
			if (val>num[j]) {
				val = num[j];
				sum = 0;
			}
			if (val == num[j]) {
				sum++;
			}

		}

		cout << "min count  " << val << " pages example " << sum << endl;
		delete[] num;

	}

	void max_in() {
		int* num;
		num = new int[number];
		for (int j = 0; j<number; j++) {
			num[j] = 0;
		}

		for (int j = 0; j<connect; j++) {
			num[in[j]]++;
		}

		for (int j = 0; j<number; j++) {
			if (step[j]) {
				num[in[from[j - 1]]]--;
			}
		}

		int sum = 0;
		int val = num[0];
		for (int j = 0; j<number; j++) {
			if (val<num[j]) {
				val = num[j];
				sum = 0;
			}
			if (val == num[j]) {
				sum++;
			}

		}
		int num_max = 0;
		for (int j = 0; j<number; j++) {
			if (num[j] == val) num_max = j;
		}
		cout << "max extra links " << val << " " << sum << endl << "num " << num_max << endl;
		delete[] num;
	}

	void av_in() {
		int* num;
		num = new int[number];
		for (int j = 0; j<number; j++) {
			num[j] = 0;
		}

		for (int j = 0; j<connect; j++) {
			num[in[j]]++;
		}

		for (int j = 0; j<number; j++) {
			if (step[j]) {
				num[in[from[j - 1]]]--;
			}
		}
		double res = 0;
		for (int j = 0; j<number; j++) {
			res += num[j];
		}
		res /= number;
		cout << "average: " << res << endl;
		delete[] num;
	}

	void min_step() {
		int* num;
		num = new int[number];
		for (int j = 0; j<number; j++) {
			num[j] = 0;
		}
		if (step[0]) {
			num[in[from[0]]]++;
		}
		for (int j = 1; j<number; j++) {
			if (step[j]) {
				num[in[from[j - 1]]]++;
			}
		}

		int sum = 0;
		int val = num[0];
		for (int j = 0; j<number; j++) {
			if (val>num[j]) {
				val = num[j];
				sum = 0;
			}
			if (val == num[j]) {
				sum++;
			}

		}

		cout << "min refers " << val << " quotes " << sum << endl;
		delete[] num;
	}

	void max_step() {
		int* num;
		num = new int[number];
		for (int j = 0; j<number; j++) {
			num[j] = 0;
		}
		if (step[0]) {
			num[in[from[0]]]++;
		}
		for (int j = 1; j<number; j++) {
			if (step[j]) {
				num[in[from[j - 1]]]++;
			}
		}

		int sum = 0;
		int val = num[0];
		for (int j = 0; j<number; j++) {
			if (val<num[j]) {
				val = num[j];
				sum = 0;
			}
			if (val == num[j]) {
				sum++;
			}

		}
		int num_max = 0;
		for (int j = 0; j<number; j++) {
			if (num[j] == val) num_max = j;
		}

		cout << "max refers:" << val << " states " << sum << endl << "number " << num_max << endl;
		delete[] num;
	}

	void av_step() {
		int* num;
		num = new int[number];
		for (int j = 0; j<number; j++) {
			num[j] = 0;
		}
		if (step[0]) {
			num[in[from[0]]]++;
		}
		for (int j = 1; j<number; j++) {
			if (step[j]) {
				num[in[from[j - 1]]]++;
			}
		}
		double res = 0;
		for (int j = 0; j<number; j++) {
			res += num[j];
		}
		res /= number;
		cout << "aver:" << res << endl;
		delete[] num;


	}
	
	void find(int Where, int From, int N, int n) {


		if (N - n) {
			for (int j = from[From - 1]; j<from[From]; j++) {
				way[n] = in[j];
				find(Where, in[j], N, n + 1);
				if (way[0]) {
					break;
				}
			}

		}


		else {
			for (int j = from[From - 1]; j<from[From]; j++) {
				if (in[j] == Where) {
					way[0] = N;
					way[N] = in[j];
				}
			}
		}
	}

	void find_a_way() {
		int N = 1;
		while (N<20) {
			delete[] way;
			way = new int[N + 1];
			way[0] = 0;
			find(Snum, Pnum, N, 1);
			if (way[0])break;
			N++;

		}
	}

	void show_way() {
		if (way[0] == 0) {
			cout << "error 404: ";
			return;
		}
		cout << "way:" << endl << Pnum << " ";
		for (int j = 1; j <= way[0]; j++) {
			cout << way[j] << " ";
		}


	}

};

int main() {


	wiki a;
	a.find_a_way();
	a.show_way();

	return 0;

}
