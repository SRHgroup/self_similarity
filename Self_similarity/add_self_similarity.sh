#! /bin/bash

datadir="/Users/annieborch/Documents/programs/Self_similarity"
#datadir="/home/projects/SRHgroup/projects/MSKCC/data/mupexi/with_tempt"
# read mupexi files

#xC='/home/projects/vaccine/people/morni/bin/xC'
#args='/home/projects/vaccine/people/morni/bin/args'

for f in ${datadir}/*.test ; do
	echo $f
	while read -u 10 q; do
		
		if [[ "$q" =~ HLA_allele* ]]; then
			echo "$q	Self_Similarity" > ${f}.sim
		elif [[ $q == "#"* ]] ; then
			echo "$q" >> ${f}.sim
		else
			pepmut=$(echo $q | awk '{print $9}')
			echo $pepmut
			echo $q | awk '{print $3}' > peptide_file # normal peptide
			echo $q
			sim=$(echo "$pepmut" | /Users/annieborch/Documents/programs/Self_similarity/pep2score_db_kernel -blf /Users/annieborch/Documents/programs/Self_similarity/matrices/BLOSUM50 -blqij /Users/annieborch/Documents/programs/Self_similarity/matrices/blosum62.qij -- peptide_file -t 2 | /Users/annieborch/Documents/programs/Self_similarity/xC | /Users/annieborch/Documents/programs/Self_similarity/args 4 )
			echo "hej:" $sim
			echo "$q	$sim" >> ${f}.sim
		fi

	done 10<${f}

done

# command
 # qsub -W group_list=vaccine -A vaccine -l nodes=1:ppn=1,mem=2gb,walltime=10:00:00 add_self_similarity.sh
