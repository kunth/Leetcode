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
