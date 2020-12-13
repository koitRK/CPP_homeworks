#include <iostream>
#include <vector>

class Toiduaine {
    std::string nimetus;
    float vp, rp, sp;
    public:
        Toiduaine(std::string n, float v, float r, float s){
            std::cout << "Creating instance of class Toiduaine with parameters" << std::endl;
            nimetus = n;
            vp = v;
            rp = r;
            sp = s;
        }
        void set_nimetus(std::string new_nimetus) {
            nimetus = new_nimetus;
        }
        void set_vp(float new_vp){
            vp = new_vp;
        }
        void set_rp(float new_rp) {
            rp = new_rp;
        }
        void set_sp(float new_sp) {
            sp = new_sp;
        }
        std::string get_nimetus(){
            return nimetus;
        }
        float get_vp(){
            return vp;
        }
        float get_rp() {
            return rp;
        }
        float get_sp() {
            return sp;
        }
};


class Toidukomponent {
    Toiduaine toiduaine;
    float kogus;
    public:
        Toidukomponent(Toiduaine t, float k):toiduaine(t){
            std::cout << "Creating instance of class Toidukomponent with parameters" << std::endl;
            toiduaine = t;
            kogus = k;
        }
        void set_toiduaine(Toiduaine new_toiduaine) {
            toiduaine = new_toiduaine;
        }
        void set_kogus(float new_kogus) {
            kogus = new_kogus;
        }
        Toiduaine get_toiduaine() {
            return toiduaine;
        }
        float get_kogus(){
            return kogus;
        }
        float get_vk() {
            return kogus * toiduaine.get_vp() / 100;
        }
        float get_rk() {
            return kogus * toiduaine.get_rp() / 100;
        }
        float get_sk() {
            return kogus * toiduaine.get_sp() / 100;
        }
};

class Toiduportsjon {
    std::vector<Toidukomponent> toidukomponendid;
    public:
        Toiduportsjon(std::vector<Toidukomponent> t) {
            std::cout << "Creating instance of class Toidukomponent with parameters" << std::endl;
            toidukomponendid = t;
        }
        void set_toidukomponendid(std::vector<Toidukomponent> new_toidukomponendid) {
            toidukomponendid = new_toidukomponendid;
        }
        std::vector<Toidukomponent> get_toidukomponendid() {
            return toidukomponendid;
        }
        float get_kogumass() {
            float kogumass = 0;
            for (Toidukomponent t : toidukomponendid){
                kogumass += t.get_kogus();
            }
            return kogumass;
        }
        float get_vkogumass() {
            int kogumass = 0;
            for (Toidukomponent t : toidukomponendid) {
                kogumass += t.get_vk();
            }
            return kogumass;
        }
        float get_rkogumass() {
            int kogumass = 0;
            for (Toidukomponent t : toidukomponendid) {
                kogumass += t.get_rk();
            }
            return kogumass;
        }
        float get_skogumass() {
            int kogumass = 0;
            for (Toidukomponent t : toidukomponendid) {
                kogumass += t.get_sk();
            }
            return kogumass;
        }
};

int main() {
    Toiduaine banana = Toiduaine("banana", 1.1, 0.3, 23);
    Toiduaine egg = Toiduaine("egg", 13, 11, 1.1);
    Toidukomponent oneBanana = Toidukomponent(banana, 120);
    Toidukomponent oneEgg = Toidukomponent(egg, 50);

    std::vector<Toidukomponent> parts{oneBanana, oneEgg, oneEgg};
    Toiduportsjon portion = (parts);

    std::cout << "Kogumass:" << portion.get_kogumass() << " Valk:" << portion.get_vkogumass() << " Rasv:" << portion.get_rkogumass() << " Susivesik:" << portion.get_skogumass() << std::endl;
    
}