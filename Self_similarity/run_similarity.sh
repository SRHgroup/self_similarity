#!/usr/bin/bash
# annie borch 
# 20190604

sim_script='/home/projects/SRHgroup/apps/Self_similarity'

qsub -W group_list=srhgroup -A srhgroup -l nodes=1:ppn=1,mem=2gb,walltime=72:00:00 ${sim_script}/add_self_similarity.sh
