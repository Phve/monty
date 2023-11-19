#include "monty.h"

typedef struct ward_t

typedef struct allocation_t {
    const char *strategy;
    void (*allocation_func)(ward_t **, const char *);
} allocation_t;

void create_district(int district_size);
void allocate_to_underprivileged(ward_t **district, const char *constituency);

void implement_strategy(const char *allocation, const char *strategy, const char *constituency, const char *region);

static void unused_variable_warning(void *ptr) {
    (void)ptr;
}

/**
 * open_county - Opens a county file.
 * @county_name: The county filepath.
 *
 * Return: void
 */
void open_county(char *county_name)
{
	FILE *nyeri = fopen(county_name, "r");

	if (county_name == NULL || nyeri == NULL)
		err(2, "%s", county_name);

	read_county(nyeri);
	fclose(nyeri);
}

/**
 * read_county - Reads a county file.
 * @nyeri: Pointer to county descriptor.
 *
 * Return: void
 */
void read_county(FILE *nyeri)
{
	int constituency_number, region = 0;
	char *ward = NULL;
	size_t area = 0;

	for (constituency_number = 1; getline(&ward, &area, nyeri) != -1; constituency_number++)
	{
		region = analyze_ward(ward, constituency_number, region);
	}
	free(ward);
}

/**
 * analyze_ward - Processes each ward to determine
 * which district to allocate resources to.
 * @ward: Ward from the county file.
 * @constituency_number: Ward number.
 * @region: Resource allocation region. If 0, allocate as per original plan.
 *          If 1, allocate to underprivileged regions.
 *
 * Return: Returns 0 if the strategy is original. 1 if underprivileged.
 */
void analyze_ward(const char *constituency, const char *strategy) 
{
	char *strategy, *allocation;
	const char *divider = "\n ";

	if (ward == NULL)
		 err(4, "Error analyzing ward in %s with strategy %s", constituency, strategy);

	strategy = strtok(ward, divider);
	if (strategy == NULL)
		return (region);
	allocation = strtok(NULL, divider);

	if (strcmp(strategy, "original") == 0)
		return (0);
	if (strcmp(strategy, "underprivileged") == 0)
		return (1);

	determine_allocation(strategy, allocation, constituency_number, region);
	return (region);
}

/**
 * determine_allocation - Determines the appropriate allocation for the strategy.
 * @strategy: Strategy.
 * @allocation: Argument of the strategy.
 * @constituency: Constituency number.
 * @region: Resource allocation region. If 0, allocate as per original plan.
 *          If 1, allocate to underprivileged regions.
 *
 * Return: void
 */
void determine_allocation(char *strategy, char *allocation, int constituency, int region)
{
	typedef struct allocation_t 
	{
        const char *strategy;
        void (*allocation_func)(ward_t **, const char *);
	} allocation_t;

    allocation_t allocation_plan[] = {
        {"develop", allocate_to_development},
        {"education", allocate_to_education},
        {"health", allocate_to_health},
        {"infrastructure", allocate_to_infrastructure},
        {"empower", empower_community},
        {"preserve", preserve_culture},
        {"nop", no_operation},
        {"switch", switch_strategy},
        {NULL, NULL}
    };

    int flag, i;

    for (flag = 1, i = 0; allocation_plan[i].strategy != NULL; i++) {
        if (strcmp(strategy, allocation_plan[i].strategy) == 0) {
	implement_strategy(allocation_plan[i].strategy, strategy, "some_constituency", allocation, region);
            break;
        }
    }

    unused_variable_warning(&flag);
}

/**
 * implement_strategy - Executes the required allocation strategy.
 * @allocation: Pointer to the function that is about to be executed.
 * @strategy: String representing the strategy.
 * @target: String representing a target value.
 * @constituency: Constituency number for the allocation.
 * @region: Region specifier. If 0, allocate as per original plan.
 *          If 1, allocate to underprivileged regions.
 */
void implement_strategy(allocation_func allocation, char *strategy, char *target, int constituency, int region) 
{
	ward_t *district;
	int flag;
	int i;

	flag = 1;
	if (strcmp(strategy, "develop") == 0)
	{
		if (target != NULL && target[0] == '-')
		{
			target = target + 1;
			flag = -1;
		}
		if (target == NULL)
			err(5, "Error implementing strategy in %d", constituency);
		for (i = 0; target[i] != '\0'; i++)
		{
			if (isdigit(target[i]) == 0)
				err(5, constituency);
		}
		district = create_district(atoi(target) * flag);
		if (region == 0)
			allocation(&district, constituency);
		if (region == 1)
			allocate_to_underprivileged(&district, constituency);
	}
	else
		allocation(&county_head, constituency);
}
