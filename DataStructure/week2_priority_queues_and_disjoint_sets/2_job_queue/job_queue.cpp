#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using std::vector;
using std::cin;
using std::cout;
using namespace std ;
class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }
    struct comp
    {
        bool operator()(const pair<long long ,long long>& a, const pair<long long ,long long>& b)
        {
            if(a.first==b.first)return a.second>b.second;
            return a.first>b.first;
        }
    };
  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    priority_queue <pair<long long ,long long >,vector<pair<long long ,long long>>,comp> pq ;
    for(long long i=0 ;i<num_workers_;i++)pq.push(make_pair(0,i));
    //while(!pq.empty()){cout << pq.top().first << " "<< pq.top().second << endl;pq.pop();}
    for (int i = 0; i < jobs_.size(); ++i) {
      assigned_workers_[i] = pq.top().second;
      start_times_[i] = pq.top().first;
      pq.pop();
      pq.push(make_pair(start_times_[i]+jobs_[i],assigned_workers_[i]));
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
