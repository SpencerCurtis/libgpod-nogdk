/*
 * Minimal implementation of itdb_get_photos_dir
 * 
 * This file provides the missing itdb_get_photos_dir function that was
 * originally in itdb_photoalbum.c but gets excluded when building without
 * GdkPixbuf support.
 *
 * This implementation is extracted from the original itdb_photoalbum.c
 * and contains no GdkPixbuf dependencies.
 */

#include <glib.h>
#include "itdb.h"
#include "itdb_private.h"

/**
 * itdb_get_photos_dir:
 * @mountpoint: the iPod mountpoint
 *
 * Retrieve the Photos directory by first calling itdb_get_control_dir()
 * and then adding 'Photos'
 *
 * Returns: path to the Photos directory or NULL if non-existent.
 * Must g_free() after use.
 *
 * Since: 0.4.0
 */
gchar *itdb_get_photos_dir (const gchar *mountpoint)
{
    gchar *p_ipod[] = {"Photos", NULL};
    /* Use an array with all possibilities, so further extension will
       be easy */
    gchar **paths[] = {p_ipod, NULL};
    gchar ***ptr;
    gchar *result = NULL;

    g_return_val_if_fail (mountpoint, NULL);

    for (ptr=paths; *ptr && !result; ++ptr)
    {
        g_free (result);
        result = itdb_resolve_path (mountpoint, (const gchar **)*ptr);
    }
    return result;
}