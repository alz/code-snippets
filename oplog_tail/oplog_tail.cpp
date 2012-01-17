/**
 * MongoDB Oplog Tail
 *
 * Kicks off a tailable cursor which monitors the oplog of a replica
 * or slave server.
 *
 * The tail starts from the current time onwards.
 */

// MongoDB includes
#include "client/dbclient.h"

using namespace std;
using namespace mongo;

int main()
{
	// Database connection - host:port
	string dbhost("127.0.0.1:27017");
	
	// Oplog table - database.collection	
	string oplog("local.oplog.rs");

	try
	{
		// Open
		DBClientConnection mongo;
		mongo.connect(dbhost);

		// Set up start time
		BSONObjBuilder bb;
		bb.appendTimestamp("ts", time(NULL) * 1000, 0);
		// Holder for last time
		BSONElement lastTime;

		Query query = QUERY("ts" << GT << bb.obj()["ts"]).sort("$natural");
		cout << "Mongo Oplog Tail - " << dbhost << "/" << oplog << endl;
		while (1)	
		{
			auto_ptr<DBClientCursor> cursor = mongo.query(oplog, query, 0, 0, 0, QueryOption_CursorTailable | QueryOption_AwaitData);
			while (1)
			{
				if (!cursor->more())
				{
					if (cursor->isDead())
						break;
				
					continue;
				}

				BSONObj obj = cursor->next();
				lastTime = obj["ts"];
				cout << obj.toString() << endl;
				break;
			}

			query = QUERY("ts" << GT << lastTime).sort("$natural");
		}
	}
	catch (DBException &e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
	return 0;
}

