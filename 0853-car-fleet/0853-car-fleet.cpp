class Solution {
    class Car{
        public:
            int position;
            int speed;
        
        Car(int position,int speed){
            this->position=position;
            this->speed=speed;
        }
    };
public:
    static bool comp(Car& a,Car& b){
        return a.position < b.position;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for(int i=0;i<speed.size();i++){
            Car obj(position[i],speed[i]);
            cars.push_back(obj);
        }
        
        sort(cars.begin(),cars.end(),comp);
        
        stack<float> s;
        for(auto car:cars){
            float time=(target-car.position)/((float)car.speed);
            while(!s.empty() && s.top()<=time){
                s.pop();
            }
            s.push(time);
        }
        return s.size();
    }
};