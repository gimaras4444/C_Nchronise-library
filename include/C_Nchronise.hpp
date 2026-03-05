#ifndef C_NCHRONISE_HPP
#define C_NCHRONISE_HPP

#include <mutex>
#include <utility>

//Βιβλιοθήκη που πέρνει σαν όρισμα την μεταβλητή mutex και της μεταβλητές του προγράμματος 
//που θα κλειδώσει ([&]()) και λειτουργεί με τρόπο παρόμοιο της synchronise στην java

namespace C_Nchronise{
    template<typename mutP, typename somef>
    void synchronize(mutP& mtx, somef&& func){
        std::lock_guard<mutP> lock(mtx);
        func();
    }
}

#endif 
