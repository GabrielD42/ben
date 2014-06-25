#include <mysql++.h>
#include <stdlib.h>

using namespace std;
using namespace mysqlpp;

int main() {
    try {
        Connection conn(false);
        conn.connect("mysqlpp", "localhost", "root", "password");
        Query query = conn.query();

        /* To insert stuff with escaping */
        query << "INSERT INTO test " << "VALUES (1, 2, 3);";
        query.execute();
        /* That's it for INSERT */

    } catch (BadQuery er) { // handle any connection or
        // query errors that may come up
        cerr << "Error: " << er.what() << endl;
        return -1;
    } catch (const BadConversion& er) {
        // Handle bad conversions
        cerr << "Conversion error: " << er.what() << endl <<
                "\tretrieved data size: " << er.retrieved <<
                ", actual size: " << er.actual_size << endl;
        return -1;
    } catch (const Exception& er) {
        // Catch-all for any other MySQL++ exceptions
        cerr << "Error: " << er.what() << endl;
        return -1;
    }

    return (EXIT_SUCCESS);
}