class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        int a = sides[0];
        int b = sides[1];
        int c = sides[2];

        if(a + b > c && a + c > b && b + c > a) {
            double A = acos((b*b + c*c - a*a) / (2.0*b*c));
            A = A * 180 / M_PI;
            double B = acos((a*a + c*c - b*b) / (2.0*a*c));
            B = B * 180 / M_PI;
            double C = acos((b*b + a*a - c*c) / (2.0*b*a));
            C = C * 180 / M_PI;
            vector<double> v = {A,B,C};
            sort(v.begin(),v.end());
            return v;
        } else {
            return {};
        }
    }
};