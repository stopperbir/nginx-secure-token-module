#ifndef _NGX_HTTP_SECURE_TOKEN_CONF_H_INCLUDED_
#define _NGX_HTTP_SECURE_TOKEN_CONF_H_INCLUDED_

#include <ngx_http.h>

struct ngx_http_secure_token_loc_conf_s;
typedef struct ngx_http_secure_token_loc_conf_s ngx_http_secure_token_loc_conf_t;

typedef ngx_int_t (*ngx_http_secure_token_build_t)(
	ngx_http_request_t* r, 
	ngx_http_secure_token_loc_conf_t *conf, 
	ngx_str_t* result);

typedef struct {
	ngx_flag_t tokenize_segments;
	ngx_flag_t encrypt_uri;
} ngx_http_secure_token_processor_conf_t;

struct ngx_http_secure_token_loc_conf_s {
	ngx_flag_t  avoid_cookies;
	ngx_hash_t  processors_hash;

	ngx_hash_t  types;
	ngx_array_t *types_keys;
	ngx_array_t* filename_prefixes;

	time_t 		expires_time;
	time_t 		cookie_token_expires_time;
	time_t 		query_token_expires_time;
	ngx_str_t	cache_scope;
	ngx_str_t	token_cache_scope;
	ngx_str_t	last_modified;
	ngx_str_t	token_last_modified;
	time_t		last_modified_time;
	time_t		token_last_modified_time;
	ngx_str_t	content_type_m3u8;
	ngx_str_t	content_type_mpd;
	ngx_str_t	content_type_f4m;

	ngx_http_complex_value_t *token;
	ngx_http_secure_token_processor_conf_t processor_conf;

	ngx_str_t encrypt_uri_key;
	ngx_str_t encrypt_uri_iv;
	ngx_http_complex_value_t *encrypt_uri_part;
	size_t encrypt_uri_hash_size;
};

#endif // _NGX_HTTP_SECURE_TOKEN_CONF_H_INCLUDED_
