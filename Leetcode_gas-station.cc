class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int ret = -1;
        if(!gas.empty())
        {
            int front = 0, rear = gas.size()-1, val = 0;
            vector<bool>visited(gas.size(), false);
            while(front <= rear)
            {
                if(val>=cost[front])
                {
                    val-=cost[front];
                    ++front;
                    if(front<=rear && !visited[front])
                    {
                        val+=gas[front];
                        visited[front] = true;
                    }
                    else
                        break;
                }
                else
                {
                    if(front<=rear && !visited[rear])
                    {
                        val+=gas[rear];
                        val-=cost[rear];
                        if(gas[rear]>=cost[rear])
                            ret = rear;
                    --rear;
                    }
                    else
                        break;
                }
            }
            if(val<0)
                ret = -1;
            else if(rear == gas.size()-1)
                ret = 0;
        }
        return ret;
    }
};

//Solution Two
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int gas_sum = accumulate(gas.begin(), gas.end(), 0);
        int cost_sum = accumulate(cost.begin(), cost.end(), 0);
        if(gas_sum < cost_sum)
            return -1;
        int begin = 0, end = 0;
        int left = 0;
        do
        {
            if(gas[begin]>=cost[begin])
                left += (gas[begin]-cost[begin++]);
            else if(gas[begin]+left>=cost[begin])
                left -= (cost[begin]-gas[begin++]);
            else// if(gas[end]-cost[end]+left>=cost[begin]-gas[begin])
            {
                end = (end + gas.size()-1) % gas.size();
                left += gas[end]-cost[end];
            }
        }
        while(begin < (end+gas.size()-1)%gas.size());
        return end;
    }
};
