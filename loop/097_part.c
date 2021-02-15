        /////////////////////////////////
        /* bubble sort +: order mark */
        /* concept: each time deliver the max/min element to the LHS/MHS */
        /* mark the order */
        for (int j = 0; j < n; j++){
            Park_lot_data[j][4] = j;
        }
        /* sort */
        for (int j = n-2; j >= 0; j--){ // sort range
            for (int k = 0; k <= j; k++){
                int sort_flag = 0; // for abbreviation
                /* swap order w.r.t. distance */
                if (Park_lot_data[k][3] > Park_lot_data[k+1][3])
                    sort_flag = 1;
                /* swap order when situation of same distance occur */
                else if (Park_lot_data[k][3] == Park_lot_data[k+1][3]){
                    /* same x coord. */
                    if (Park_lot_data[k][0] > Park_lot_data[k+1][0])
                        sort_flag = 1;
                    /* same y coord. */
                    else if (Park_lot_data[k][0] == Park_lot_data[k+1][0]){
                        if (Park_lot_data[k][1] > Park_lot_data[k+1][1])
                            sort_flag = 1;
                    }
                }
                /* swap the marked term */
                if (sort_flag == 1){
                    Park_lot_data[k][3] ^= Park_lot_data[k+1][3] ^= Park_lot_data[k][3] ^= Park_lot_data[k+1][3];
                    Park_lot_data[k][4] ^= Park_lot_data[k+1][4] ^= Park_lot_data[k][4] ^= Park_lot_data[k+1][4];
                }
            }
        }
        /////////////////////////////////