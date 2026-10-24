class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};

        auto convert = [&](string date) {
            int month = stoi(date.substr(0,2));
            int day = stoi(date.substr(3,2));
            int total = 0;
            for(int i=0; i<month-1; i++) total += daysInMonth[i];
            total += day;
            return total;
        };

        int aStart = convert(arriveAlice);
        int aEnd   = convert(leaveAlice);
        int bStart = convert(arriveBob);
        int bEnd   = convert(leaveBob);

        int start = max(aStart, bStart);
        int end   = min(aEnd, bEnd);

        return (start <= end) ? (end - start + 1) : 0;
    }
};
