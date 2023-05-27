pkgname="openutils-date_time"
pkgver="1.1.0"
pkgrel="1"
pkgdesc="DATE-TIME : The Date/Time Management Library"
arch=("x86_64" "i686")
conflicts=('openutils-date_time')
depends=(gcc)
license=("GNU GPL v3.0")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/date.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/time.hh")

sha512sums=(
	"ac9d35bc980ec909ae093c1b3d48a6add504deae19a37bfc06ef96343b6ae69f9f33b7512e740786ceb16695b5968b017b38542705d11d6d2d899f04df808592"
	"af91e02c62742c8a6a1f38cd69c2b17f100bef40bd2b79519569fa0851a408b097865c88405ee4013eb1a55daac6811f5c160af219d82962bf1c0dfe611ca138")

package() {
	echo "DATE-TIME : The Date/Time Management Library"
	mkdir -p "${pkgdir}/usr/include/openutils/date-time"
	cp "${srcdir}/date.hh" "${pkgdir}/usr/include/openutils/date-time/date.hh"
	cp "${srcdir}/time.hh" "${pkgdir}/usr/include/openutils/date-time/time.hh"
	echo "Done!"
}
