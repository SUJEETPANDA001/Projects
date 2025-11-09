#!/bin/bash
# ============================================
# Log Monitoring Script
# ============================================

LOG_FILE="/var/log/system_maintenance.log"
TARGET_LOG="/var/log/syslog"
ALERT_WORDS=("error" "fail" "warning")
ALERT_EMAIL="admin@example.com"

if [ "$EUID" -ne 0 ]; then
    echo "Please run as root." | tee -a "$LOG_FILE"
    exit 1
fi

trap 'echo "[$(date)] ERROR: Command failed at line $LINENO" | tee -a "$LOG_FILE"' ERR

echo "[$(date)] Monitoring logs for alerts..." | tee -a "$LOG_FILE"

for WORD in "${ALERT_WORDS[@]}"; do
    MATCHES=$(grep -i "$WORD" "$TARGET_LOG" | tail -n 5)
    if [ -n "$MATCHES" ]; then
        echo "[$(date)] ALERT: Found '$WORD' in logs!" | tee -a "$LOG_FILE"
        echo "$MATCHES" | tee -a "$LOG_FILE"
    fi
done
