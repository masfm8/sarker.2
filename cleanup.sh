#!/bin/bash

# Remove message queues
for id in $(ipcs -q | grep '^[0-9]' | awk '{print $2}'); do
    ipcrm -q $id
done

# Remove shared memory segments
for id in $(ipcs -m | grep '^[0-9]' | awk '{print $2}'); do
    ipcrm -m $id
done

echo "IPC resources cleaned up."
