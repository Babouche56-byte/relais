int is_valid_ip(const char *ip) {
    if (ip == NULL) return 0;
    
    int segments = 0;
    int digits = 0;
    int value = 0;
    
    while (*ip) {
        if (*ip == '.') {
            if (digits == 0) return 0;
            segments++;
            digits = 0;
            value = 0;
        } else if (*ip >= '0' && *ip <= '9') {
            value = value * 10 + (*ip - '0');
            digits++;
            if (value > 255 || digits > 3) return 0;
        } else {
            return 0;
        }
        ip++;
    }
    
    return segments == 3 && digits > 0;
}

int is_valid_port(int port) {
    return port >= 1024 && port <= 65535;  // Ports non privilégiés
}
