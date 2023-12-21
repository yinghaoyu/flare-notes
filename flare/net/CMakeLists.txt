set(net_SRCS
  cos/ops/bucket/get_bucket.cc
  cos/ops/object/delete_multiple_objects.cc
  cos/ops/object/delete_object.cc
  cos/ops/object/get_object.cc
  cos/ops/object/put_object.cc
  cos/ops/task.cc
  cos/cos_channel.cc
  cos/cos_client.cc
  cos/cos_status.cc
  cos/signature.cc
  # hbase/proto/
  hbase/call_context.cc
  hbase/call_context_factory.cc
  hbase/hbase_channel.cc
  hbase/hbase_client_controller.cc
  hbase/hbase_client_protocol.cc
  hbase/hbase_controller_common.cc
  hbase/hbase_server_controller.cc
  hbase/hbase_server_protocol.cc
  hbase/hbase_service.cc
  hbase/message.cc
  http/dry_run_channel.cc
  http/http_client.cc
  http/http_headers.cc
  http/http_message.cc
  http/http_request.cc
  http/http_response.cc
  http/packet_desc.cc
  http/query_string.cc
  http/types.cc
  http/utility.cc
  internal/http_engine.cc
  internal/http_task.cc
  redis/nslb_registration.cc
  redis/reader.cc
  redis/redis_channel.cc
  redis/redis_client.cc
  redis/redis_command.cc
  redis/redis_protocol.cc
  )

add_library(flare_net ${net_SRCS})
target_link_libraries(flare_net flare_rpc flare_base flare_fiber)

set(IN_LIBS
  flare_init
  flare_io
  gtest
  gmock
  benchmark
  rapidxml
  )

add_subdirectory(cos)
add_subdirectory(hbase)
add_subdirectory(http)
add_subdirectory(internal)
add_subdirectory(redis)
