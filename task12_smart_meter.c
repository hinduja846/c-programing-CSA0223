/*
 * Day-4 redesign: 15-minute watt-hour readings, time-of-day tariffs,
 * annual totals, and tariffs configurable at runtime (no recompilation).
 * Illustrative tariffs are entered by the operator in paise/kWh.
 */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef enum { OFF_PEAK = 0, PEAK = 1 } tariff_slot;

typedef struct {
    uint64_t off_peak_paise_per_kwh;
    uint64_t peak_paise_per_kwh;
    uint64_t fixed_monthly_paise;
} tariff_config;

static int read_u64(const char *prompt, uint64_t *out)
{
    printf("%s", prompt);
    return scanf("%" SCNu64, out) == 1;
}
static uint64_t charge_paise(uint64_t watt_hours, uint64_t rate_paise_per_kwh)
{
    /* Round once to nearest paise: (Wh * paise/kWh) / 1000. */
    return (watt_hours * rate_paise_per_kwh + 500u) / 1000u;
}
int main(void)
{
    tariff_config t;
    uint64_t readings, annual_wh = 0, off_peak_wh = 0, peak_wh = 0;
    uint64_t wh, total_paise;
    if (!read_u64("Number of 15-minute readings to enter: ", &readings) || readings > 35040u) {
        fprintf(stderr, "Invalid reading count (must be 0..35040).\\n");
        return 1;
    }
    if (!read_u64("Off-peak tariff (paise/kWh): ", &t.off_peak_paise_per_kwh) ||
        !read_u64("Peak tariff (paise/kWh): ", &t.peak_paise_per_kwh) ||
        !read_u64("Fixed monthly charge (paise): ", &t.fixed_monthly_paise)) {
        fprintf(stderr, "Invalid tariff input.\\n");
        return 1;
    }
    for (uint64_t i = 0; i < readings; ++i) {
        unsigned int slot;
        printf("Reading %" PRIu64 " watt-hours and slot (0=off-peak, 1=peak): ", i + 1);
        if (scanf("%" SCNu64 " %u", &wh, &slot) != 2 || slot > 1u) {
            fprintf(stderr, "Invalid reading or slot.\\n");
            return 1;
        }
        if (UINT64_MAX - annual_wh < wh) {
            fprintf(stderr, "Annual watt-hour total overflow.\\n");
            return 1;
        }
        annual_wh += wh;
        if (slot == PEAK) {
            if (UINT64_MAX - peak_wh < wh) return 1;
            peak_wh += wh;
        } else {
            if (UINT64_MAX - off_peak_wh < wh) return 1;
            off_peak_wh += wh;
        }
    }
    uint64_t off_charge = charge_paise(off_peak_wh, t.off_peak_paise_per_kwh);
    uint64_t peak_charge = charge_paise(peak_wh, t.peak_paise_per_kwh);
    total_paise = t.fixed_monthly_paise + off_charge + peak_charge;
    printf("Total energy: %" PRIu64 " Wh (%.3f kWh)\\n",
           annual_wh, (double)annual_wh / 1000.0);
    printf("Off-peak: %" PRIu64 " Wh; peak: %" PRIu64 " Wh\\n", off_peak_wh, peak_wh);
    printf("Energy charge: Rs %" PRIu64 ".%02" PRIu64 "\\n",
           (off_charge + peak_charge) / 100u, (off_charge + peak_charge) % 100u);
    printf("Total including entered fixed charge: Rs %" PRIu64 ".%02" PRIu64 "\\n",
           total_paise / 100u, total_paise % 100u);
    return 0;
}
