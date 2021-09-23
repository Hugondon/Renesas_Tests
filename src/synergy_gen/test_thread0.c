/* generated thread source file - do not edit */
#include "test_thread0.h"

TX_THREAD test_thread0;
void test_thread0_create(void);
static void test_thread0_func(ULONG thread_input);
static uint8_t test_thread0_stack[1024] BSP_PLACE_IN_SECTION_V2(".stack.test_thread0") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
TX_MUTEX g_new_mutex0;
TX_SEMAPHORE g_new_semaphore0;
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void test_thread0_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */
    UINT err_g_new_mutex0;
    err_g_new_mutex0 = tx_mutex_create (&g_new_mutex0, (CHAR *) "New Mutex", TX_NO_INHERIT);
    if (TX_SUCCESS != err_g_new_mutex0)
    {
        tx_startup_err_callback (&g_new_mutex0, 0);
    }
    UINT err_g_new_semaphore0;
    err_g_new_semaphore0 = tx_semaphore_create (&g_new_semaphore0, (CHAR *) "New Semaphore", 0);
    if (TX_SUCCESS != err_g_new_semaphore0)
    {
        tx_startup_err_callback (&g_new_semaphore0, 0);
    }

    UINT err;
    err = tx_thread_create (&test_thread0, (CHAR *) "Test Thread", test_thread0_func, (ULONG) NULL, &test_thread0_stack,
                            1024, 1, 1, 1, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&test_thread0, 0);
    }
}

static void test_thread0_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    test_thread0_entry ();
}
