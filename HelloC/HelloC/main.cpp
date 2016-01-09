//
//  main.cpp
//  HelloC
//
//  Created by hatlonely on 15/12/21.
//  Copyright © 2015年 hatlonely. All rights reserved.
//

#define MAIN_NAMESPACE(name) namespace name { extern int main(int argc, char *argv[]); }

// boost
MAIN_NAMESPACE(boost_lexical_cast)
MAIN_NAMESPACE(boost_assign)
MAIN_NAMESPACE(boost_regex)
MAIN_NAMESPACE(boost_algorithm_string)
MAIN_NAMESPACE(boost_any)
MAIN_NAMESPACE(boost_bimap)
MAIN_NAMESPACE(boost_flat)
MAIN_NAMESPACE(boost_heap)
MAIN_NAMESPACE(boost_multi_index)
MAIN_NAMESPACE(boost_property_tree)
MAIN_NAMESPACE(boost_crc)

// hiredis
MAIN_NAMESPACE(hiredis_hiredis)

// mysql
MAIN_NAMESPACE(mysql_connector_c)

// c++11
MAIN_NAMESPACE(c11_container)
MAIN_NAMESPACE(c11_semantics)
MAIN_NAMESPACE(c11_random)
MAIN_NAMESPACE(c11_regex)
MAIN_NAMESPACE(c11_smart_ptr)
MAIN_NAMESPACE(c11_move)
MAIN_NAMESPACE(c11_thread)

// protobuf
MAIN_NAMESPACE(protobuf_protobuf)

// thrift
MAIN_NAMESPACE(thrift_tutorial_server)
MAIN_NAMESPACE(thrift_tutorial_client)

// socket
MAIN_NAMESPACE(socket_server1)
MAIN_NAMESPACE(socket_server2)
MAIN_NAMESPACE(socket_server3)
MAIN_NAMESPACE(socket_client)

int main(int argc, char* argv[]) {
    return boost_crc::main(argc, argv);
}