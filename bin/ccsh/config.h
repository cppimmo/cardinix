#ifndef _CCSH_CONFIG_H_
#define _CCSH_CONFIG_H_

/* Structure containing configuration options. */
struct ccsh_config {
    
};
typedef struct ccsh_config ccsh_config_t;

extern char *ccsh_configs[];

int ccsh_ccopen(char *filename);
int ccsh_cclose(void);

#endif /* !_CCSH_CONFIG_H_ */
